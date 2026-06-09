// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "CrowSearchAlgorithm.hpp"

#include <algorithm>
#include <limits>

namespace algorithm {
namespace {

constexpr double kInfinity = std::numeric_limits<double>::infinity();

void ensureOpenWarehouse(std::vector<bool>& solution, std::mt19937& rng) {
    if (std::any_of(solution.begin(), solution.end(), [](bool open) { return open; })) {
        return;
    }

    std::uniform_int_distribution<std::size_t> pick(0, solution.size() - 1);
    solution[pick(rng)] = true;
}

std::vector<std::pair<int, int>> buildAssignments(const std::vector<std::vector<double>>& customer,
                                                  const std::vector<bool>& openWarehouses) {
    std::vector<std::pair<int, int>> assignments;
    assignments.reserve(customer.size());

    for (std::size_t customerIndex = 0; customerIndex < customer.size(); ++customerIndex) {
        int warehouseIndex = -1;
        double minCost = kInfinity;

        for (std::size_t warehouse = 0; warehouse < openWarehouses.size(); ++warehouse) {
            if (openWarehouses[warehouse] && customer[customerIndex][warehouse] < minCost) {
                minCost = customer[customerIndex][warehouse];
                warehouseIndex = static_cast<int>(warehouse);
            }
        }

        assignments.emplace_back(static_cast<int>(customerIndex), warehouseIndex);
    }

    return assignments;
}

} // namespace

double CrowSearchAlgorithm::closed_interval_rand(std::mt19937& rng, double x0, double x1) {
    std::uniform_real_distribution<double> distribution(x0, x1);
    return distribution(rng);
}

double CrowSearchAlgorithm::UFLP(int loc,
                                 int cus,
                                 const std::vector<std::vector<double>>& customer,
                                 const std::vector<double>& location,
                                 const std::vector<bool>& per) {
    double cost = 0.0;
    bool hasOpenWarehouse = false;

    for (int warehouse = 0; warehouse < loc; ++warehouse) {
        if (per[static_cast<std::size_t>(warehouse)]) {
            cost += location[static_cast<std::size_t>(warehouse)];
            hasOpenWarehouse = true;
        }
    }

    if (!hasOpenWarehouse) {
        return kInfinity;
    }

    for (int customerIndex = 0; customerIndex < cus; ++customerIndex) {
        double minCost = kInfinity;
        for (int warehouse = 0; warehouse < loc; ++warehouse) {
            if (per[static_cast<std::size_t>(warehouse)] &&
                customer[static_cast<std::size_t>(customerIndex)][static_cast<std::size_t>(warehouse)] < minCost) {
                minCost = customer[static_cast<std::size_t>(customerIndex)][static_cast<std::size_t>(warehouse)];
            }
        }
        cost += minCost;
    }

    return cost;
}

std::vector<std::pair<int, int>> CrowSearchAlgorithm::solve(const Problem& problem) const {
    const int loc = problem.getNumberOfWarehouses();
    const int cus = problem.getNumberOfCustomers();

    if (loc <= 0 || cus <= 0 || population_size <= 0) {
        return {};
    }

    std::mt19937 rng(std::random_device{}());

    const auto& customers = problem.getCustomers();
    const auto& warehouses = problem.getWarehouses();

    std::vector<double> location(static_cast<std::size_t>(loc));
    std::vector<std::vector<double>> customer(static_cast<std::size_t>(cus), std::vector<double>(static_cast<std::size_t>(loc)));

    for (int warehouse = 0; warehouse < loc; ++warehouse) {
        location[static_cast<std::size_t>(warehouse)] = warehouses[static_cast<std::size_t>(warehouse)].getFixedCost();
    }

    for (int customerIndex = 0; customerIndex < cus; ++customerIndex) {
        customer[static_cast<std::size_t>(customerIndex)] =
            customers[static_cast<std::size_t>(customerIndex)].getAllocationCosts();
    }

    const int populationSize = population_size;
    const double awarenessProbability = awareness_probability;
    const int maxIterations = std::max(1, function_evaluations / populationSize);

    std::vector<int> follow(static_cast<std::size_t>(populationSize), 0);
    std::vector<double> objCrows(static_cast<std::size_t>(populationSize), 0.0);
    std::vector<double> objMemory(static_cast<std::size_t>(populationSize), 0.0);

    std::vector<std::vector<bool>> xCrows(static_cast<std::size_t>(populationSize), std::vector<bool>(static_cast<std::size_t>(loc)));
    std::vector<std::vector<bool>> xMemory(static_cast<std::size_t>(populationSize), std::vector<bool>(static_cast<std::size_t>(loc)));

    double globalBest = kInfinity;
    std::vector<bool> globalBestMemory(static_cast<std::size_t>(loc), false);

    for (int crow = 0; crow < populationSize; ++crow) {
        for (int warehouse = 0; warehouse < loc; ++warehouse) {
            xCrows[static_cast<std::size_t>(crow)][static_cast<std::size_t>(warehouse)] =
                closed_interval_rand(rng, 0.0, 1.0) < 0.5;
        }

        ensureOpenWarehouse(xCrows[static_cast<std::size_t>(crow)], rng);
        xMemory[static_cast<std::size_t>(crow)] = xCrows[static_cast<std::size_t>(crow)];
        objMemory[static_cast<std::size_t>(crow)] =
            UFLP(loc, cus, customer, location, xMemory[static_cast<std::size_t>(crow)]);
    }

    std::uniform_int_distribution<int> followDistribution(0, populationSize - 1);

    for (int iter = 0; iter < maxIterations; ++iter) {
        for (int crow = 0; crow < populationSize; ++crow) {
            const auto crowIndex = static_cast<std::size_t>(crow);
            objCrows[crowIndex] = UFLP(loc, cus, customer, location, xCrows[crowIndex]);

            if (objCrows[crowIndex] < objMemory[crowIndex]) {
                objMemory[crowIndex] = objCrows[crowIndex];
                xMemory[crowIndex] = xCrows[crowIndex];
            }

            if (objMemory[crowIndex] < globalBest) {
                globalBest = objMemory[crowIndex];
                globalBestMemory = xMemory[crowIndex];
            }
        }

        for (int crow = 0; crow < populationSize; ++crow) {
            follow[static_cast<std::size_t>(crow)] = followDistribution(rng);
        }

        for (int crow = 0; crow < populationSize; ++crow) {
            const auto crowIndex = static_cast<std::size_t>(crow);
            if (closed_interval_rand(rng, 0.0, 1.0) > awarenessProbability) {
                const auto followIndex = static_cast<std::size_t>(follow[crowIndex]);
                for (int warehouse = 0; warehouse < loc; ++warehouse) {
                    const auto warehouseIndex = static_cast<std::size_t>(warehouse);
                    const bool memoryDiff = xMemory[followIndex][warehouseIndex] != xMemory[crowIndex][warehouseIndex];
                    const bool randomStep = closed_interval_rand(rng, 0.0, 1.0) < 0.5;
                    xCrows[crowIndex][warehouseIndex] = xMemory[crowIndex][warehouseIndex] != (randomStep && memoryDiff);
                }
            } else {
                for (int warehouse = 0; warehouse < loc; ++warehouse) {
                    xCrows[crowIndex][static_cast<std::size_t>(warehouse)] =
                        closed_interval_rand(rng, 0.0, 1.0) < 0.5;
                }
            }

            ensureOpenWarehouse(xCrows[crowIndex], rng);
        }
    }

    return buildAssignments(customer, globalBestMemory);
}

} // namespace algorithm
