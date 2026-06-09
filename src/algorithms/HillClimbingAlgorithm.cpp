// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "HillClimbingAlgorithm.hpp"

#include <algorithm>
#include <cstdint>
#include <limits>

namespace algorithm {
namespace {

constexpr double kInfinity = std::numeric_limits<double>::infinity();

struct CustomerBest {
    int best_warehouse = -1;
    double best_cost = kInfinity;
    double second_best_cost = kInfinity;
};

std::vector<CustomerBest> getCustomerBests(const Problem& problem,
                                           const std::vector<std::uint8_t>& openWarehouses) {
    const auto& customers = problem.getCustomers();
    std::vector<CustomerBest> bests(customers.size());

    for (std::size_t customer_index = 0; customer_index < customers.size(); ++customer_index) {
        const auto& allocationCosts = customers[customer_index].getAllocationCosts();
        auto& best = bests[customer_index];

        for (std::size_t warehouse_index = 0; warehouse_index < openWarehouses.size(); ++warehouse_index) {
            if (!openWarehouses[warehouse_index]) {
                continue;
            }

            const double cost = allocationCosts[warehouse_index];
            if (cost < best.best_cost) {
                best.second_best_cost = best.best_cost;
                best.best_cost = cost;
                best.best_warehouse = static_cast<int>(warehouse_index);
            } else if (cost < best.second_best_cost) {
                best.second_best_cost = cost;
            }
        }
    }

    return bests;
}

} // namespace

double HillClimbingAlgorithm::calculateCost(const Problem& problem, const WarehouseMask& openWarehouses) const {
    double totalCost = 0.0;

    const auto& warehouses = problem.getWarehouses();
    for (std::size_t i = 0; i < openWarehouses.size(); ++i) {
        if (openWarehouses[i]) {
            totalCost += warehouses[i].getFixedCost();
        }
    }

    for (const auto& best : getCustomerBests(problem, openWarehouses)) {
        if (best.best_warehouse == -1) {
            return kInfinity;
        }
        totalCost += best.best_cost;
    }

    return totalCost;
}

void HillClimbingAlgorithm::getInitialSolution(const Problem& problem, WarehouseMask& openWarehouses) const {
    openWarehouses.assign(static_cast<std::size_t>(problem.getNumberOfWarehouses()), 1);
}

double HillClimbingAlgorithm::getBestNeighborCost(const Problem& problem,
                                                  const WarehouseMask& currentSolution,
                                                  double currentCost,
                                                  WarehouseMask& bestNeighbor) const {
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    const auto customerBests = getCustomerBests(problem, currentSolution);
    const int openCount = static_cast<int>(std::count(currentSolution.begin(), currentSolution.end(), 1));

    int bestWarehouseToToggle = -1;
    double bestDelta = 0.0;

    for (std::size_t warehouse_index = 0; warehouse_index < currentSolution.size(); ++warehouse_index) {
        double delta = 0.0;

        if (currentSolution[warehouse_index]) {
            if (openCount <= 1) {
                continue;
            }

            delta -= warehouses[warehouse_index].getFixedCost();
            for (std::size_t customer_index = 0; customer_index < customers.size(); ++customer_index) {
                if (customerBests[customer_index].best_warehouse == static_cast<int>(warehouse_index)) {
                    delta += customerBests[customer_index].second_best_cost - customerBests[customer_index].best_cost;
                }
            }
        } else {
            delta += warehouses[warehouse_index].getFixedCost();
            for (std::size_t customer_index = 0; customer_index < customers.size(); ++customer_index) {
                const auto& allocationCosts = customers[customer_index].getAllocationCosts();
                const double candidateCost = allocationCosts[warehouse_index];
                if (candidateCost < customerBests[customer_index].best_cost) {
                    delta += candidateCost - customerBests[customer_index].best_cost;
                }
            }
        }

        if (delta < bestDelta) {
            bestDelta = delta;
            bestWarehouseToToggle = static_cast<int>(warehouse_index);
        }
    }

    bestNeighbor = currentSolution;
    if (bestWarehouseToToggle != -1) {
        bestNeighbor[static_cast<std::size_t>(bestWarehouseToToggle)] =
            static_cast<std::uint8_t>(!bestNeighbor[static_cast<std::size_t>(bestWarehouseToToggle)]);
    }

    return currentCost + bestDelta;
}

std::vector<std::pair<int, int>> HillClimbingAlgorithm::solve(const Problem& problem) const {
    WarehouseMask currentSolution;
    getInitialSolution(problem, currentSolution);

    double currentCost = calculateCost(problem, currentSolution);
    while (true) {
        WarehouseMask neighborSolution;
        const double neighborCost = getBestNeighborCost(problem, currentSolution, currentCost, neighborSolution);

        if (neighborCost >= currentCost) {
            break;
        }

        currentSolution = std::move(neighborSolution);
        currentCost = neighborCost;
    }

    const auto& customers = problem.getCustomers();
    std::vector<std::pair<int, int>> assignments;
    assignments.reserve(customers.size());

    for (std::size_t customer_index = 0; customer_index < customers.size(); ++customer_index) {
        const auto& allocationCosts = customers[customer_index].getAllocationCosts();
        int bestWarehouse = -1;
        double minCost = kInfinity;

        for (std::size_t warehouse_index = 0; warehouse_index < currentSolution.size(); ++warehouse_index) {
            if (currentSolution[warehouse_index] && allocationCosts[warehouse_index] < minCost) {
                minCost = allocationCosts[warehouse_index];
                bestWarehouse = static_cast<int>(warehouse_index);
            }
        }

        assignments.emplace_back(static_cast<int>(customer_index), bestWarehouse);
    }

    return assignments;
}

} // namespace algorithm
