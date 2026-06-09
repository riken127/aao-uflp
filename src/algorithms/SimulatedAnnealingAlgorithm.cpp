// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "SimulatedAnnealingAlgorithm.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <utility>

namespace algorithm {
namespace {

constexpr double kInfinity = std::numeric_limits<double>::infinity();

std::vector<int> buildGreedyAssignment(const Problem& problem) {
    const auto& customers = problem.getCustomers();
    const int numCustomers = problem.getNumberOfCustomers();
    const int numWarehouses = problem.getNumberOfWarehouses();
    std::vector<int> assignment(static_cast<std::size_t>(numCustomers), -1);

    for (int customer = 0; customer < numCustomers; ++customer) {
        const auto& allocationCosts = customers[static_cast<std::size_t>(customer)].getAllocationCosts();
        int bestWarehouse = 0;
        double bestCost = allocationCosts.front();

        for (int warehouse = 1; warehouse < numWarehouses; ++warehouse) {
            if (allocationCosts[static_cast<std::size_t>(warehouse)] < bestCost) {
                bestCost = allocationCosts[static_cast<std::size_t>(warehouse)];
                bestWarehouse = warehouse;
            }
        }

        assignment[static_cast<std::size_t>(customer)] = bestWarehouse;
    }

    return assignment;
}

} // namespace

double SimulatedAnnealingAlgorithm::randomUnit() const {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(rng);
}

int SimulatedAnnealingAlgorithm::randomInt(int maxExclusive) const {
    std::uniform_int_distribution<int> distribution(0, maxExclusive - 1);
    return distribution(rng);
}

double SimulatedAnnealingAlgorithm::calculateCost(const std::vector<int>& assignment, const Problem& problem) const {
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    std::vector<int> openCounts(warehouses.size(), 0);
    double totalCost = 0.0;

    for (std::size_t customer = 0; customer < assignment.size(); ++customer) {
        const int warehouse = assignment[customer];
        if (warehouse < 0 || warehouse >= static_cast<int>(warehouses.size())) {
            return kInfinity;
        }

        totalCost += customers[customer].getAllocationCosts()[static_cast<std::size_t>(warehouse)];
        ++openCounts[static_cast<std::size_t>(warehouse)];
    }

    for (std::size_t warehouse = 0; warehouse < openCounts.size(); ++warehouse) {
        if (openCounts[warehouse] > 0) {
            totalCost += warehouses[warehouse].getFixedCost();
        }
    }

    return totalCost;
}

SimulatedAnnealingAlgorithm::Solution
SimulatedAnnealingAlgorithm::generateNeighbor(const Solution& current_solution, const Problem& problem) const {
    Solution newSolution = current_solution;
    const int numCustomers = problem.getNumberOfCustomers();
    const int numWarehouses = problem.getNumberOfWarehouses();
    const int perturbations = std::max(1, std::min(numCustomers / 10, 25));

    std::vector<int> customerOrder(static_cast<std::size_t>(numCustomers));
    std::iota(customerOrder.begin(), customerOrder.end(), 0);
    std::shuffle(customerOrder.begin(), customerOrder.end(), rng);

    for (int i = 0; i < perturbations; ++i) {
        newSolution.assignment[static_cast<std::size_t>(customerOrder[static_cast<std::size_t>(i)])] =
            randomInt(numWarehouses);
    }

    localSearch(newSolution, problem, 6);
    return newSolution;
}

void SimulatedAnnealingAlgorithm::localSearch(Solution& solution, const Problem& problem, int tabu_tenure) const {
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    const int numWarehouses = problem.getNumberOfWarehouses();
    std::vector<int> openCounts(warehouses.size(), 0);
    std::vector<int> tabuUntil(warehouses.size(), 0);

    for (const int warehouse : solution.assignment) {
        ++openCounts[static_cast<std::size_t>(warehouse)];
    }

    solution.total_cost = calculateCost(solution.assignment, problem);

    int iteration = 0;
    int iterationsWithoutImprovement = 0;
    while (iterationsWithoutImprovement < 20) {
        bool improved = false;

        for (std::size_t customer = 0; customer < solution.assignment.size(); ++customer) {
            const int currentWarehouse = solution.assignment[customer];
            int bestWarehouse = currentWarehouse;
            double bestDelta = 0.0;

            for (int warehouse = 0; warehouse < numWarehouses; ++warehouse) {
                if (warehouse == currentWarehouse || tabuUntil[static_cast<std::size_t>(warehouse)] > iteration) {
                    continue;
                }

                double delta = customers[customer].getAllocationCosts()[static_cast<std::size_t>(warehouse)] -
                               customers[customer].getAllocationCosts()[static_cast<std::size_t>(currentWarehouse)];

                if (openCounts[static_cast<std::size_t>(warehouse)] == 0) {
                    delta += warehouses[static_cast<std::size_t>(warehouse)].getFixedCost();
                }
                if (openCounts[static_cast<std::size_t>(currentWarehouse)] == 1) {
                    delta -= warehouses[static_cast<std::size_t>(currentWarehouse)].getFixedCost();
                }

                if (delta < bestDelta) {
                    bestDelta = delta;
                    bestWarehouse = warehouse;
                }
            }

            if (bestWarehouse != currentWarehouse) {
                --openCounts[static_cast<std::size_t>(currentWarehouse)];
                ++openCounts[static_cast<std::size_t>(bestWarehouse)];
                solution.assignment[customer] = bestWarehouse;
                solution.total_cost += bestDelta;
                tabuUntil[static_cast<std::size_t>(currentWarehouse)] = iteration + tabu_tenure;
                improved = true;
            }
        }

        if (improved) {
            iterationsWithoutImprovement = 0;
        } else {
            ++iterationsWithoutImprovement;
        }
        ++iteration;
    }
}

SimulatedAnnealingAlgorithm::Solution
SimulatedAnnealingAlgorithm::adaptivePerturbation(const Solution& current_solution,
                                                  const Problem& problem,
                                                  int iteration) const {
    Solution newSolution = current_solution;
    const int numCustomers = problem.getNumberOfCustomers();
    const int numWarehouses = problem.getNumberOfWarehouses();
    const int perturbationSize = std::max(1, (iteration % 2 == 0) ? numCustomers / 3 : numCustomers / 5);

    std::vector<int> customerOrder(static_cast<std::size_t>(numCustomers));
    std::iota(customerOrder.begin(), customerOrder.end(), 0);
    std::shuffle(customerOrder.begin(), customerOrder.end(), rng);

    for (int i = 0; i < perturbationSize; ++i) {
        newSolution.assignment[static_cast<std::size_t>(customerOrder[static_cast<std::size_t>(i)])] =
            randomInt(numWarehouses);
    }

    newSolution.total_cost = calculateCost(newSolution.assignment, problem);
    return newSolution;
}

std::vector<std::pair<int, int>> SimulatedAnnealingAlgorithm::solve(const Problem& problem) const {
    const int numWarehouses = problem.getNumberOfWarehouses();
    const int numCustomers = problem.getNumberOfCustomers();

    if (numWarehouses <= 0 || numCustomers <= 0) {
        return {};
    }

    Solution currentSolution;
    currentSolution.assignment = buildGreedyAssignment(problem);
    currentSolution.total_cost = calculateCost(currentSolution.assignment, problem);
    localSearch(currentSolution, problem, 6);

    Solution bestSolution = currentSolution;
    double temperature = initial_temperature;
    int iteration = 0;

    while (iterations_per_temp > 0 && cooling_rate > 0.0 && cooling_rate < 1.0 && temperature > final_temperature) {
        for (int i = 0; i < iterations_per_temp; ++i) {
            Solution newSolution = generateNeighbor(currentSolution, problem);
            const double deltaCost = newSolution.total_cost - currentSolution.total_cost;

            if (deltaCost < 0.0 || std::exp(-deltaCost / temperature) > randomUnit()) {
                currentSolution = std::move(newSolution);
            }

            if (currentSolution.total_cost < bestSolution.total_cost) {
                bestSolution = currentSolution;
            }
        }

        temperature *= cooling_rate;

        if (++iteration % 30 == 0) {
            currentSolution = adaptivePerturbation(bestSolution, problem, iteration);
            localSearch(currentSolution, problem, 6);
        }
    }

    std::vector<std::pair<int, int>> result;
    result.reserve(static_cast<std::size_t>(numCustomers));

    for (int customer = 0; customer < numCustomers; ++customer) {
        result.emplace_back(customer, bestSolution.assignment[static_cast<std::size_t>(customer)]);
    }

    return result;
}

} // namespace algorithm
