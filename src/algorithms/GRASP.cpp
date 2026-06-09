// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "GRASP.hpp"

#include <algorithm>

namespace algorithm {

GRASP::GRASP(double alpha)
    : alpha(std::clamp(alpha, 0.0, 1.0)), rng(std::random_device{}()) {}

void GRASP::initialize(const Problem& problem) {
    number_of_customers = problem.getNumberOfCustomers();
    number_of_warehouses = problem.getNumberOfWarehouses();

    fixed_costs.assign(static_cast<std::size_t>(number_of_warehouses), 0.0);
    allocation_costs.assign(static_cast<std::size_t>(number_of_warehouses),
                            std::vector<double>(static_cast<std::size_t>(number_of_customers), 0.0));

    const auto& warehouses = problem.getWarehouses();
    for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
        fixed_costs[static_cast<std::size_t>(warehouse)] = warehouses[static_cast<std::size_t>(warehouse)].getFixedCost();
    }

    const auto& customers = problem.getCustomers();
    for (int customer = 0; customer < number_of_customers; ++customer) {
        const auto& costs = customers[static_cast<std::size_t>(customer)].getAllocationCosts();
        for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
            allocation_costs[static_cast<std::size_t>(warehouse)][static_cast<std::size_t>(customer)] =
                costs[static_cast<std::size_t>(warehouse)];
        }
    }

    best_assignment.assign(static_cast<std::size_t>(number_of_customers), -1);
    warehouse_open.assign(static_cast<std::size_t>(number_of_warehouses), 0);
    customer_assignment.assign(static_cast<std::size_t>(number_of_customers), -1);
    best_warehouse_open.assign(static_cast<std::size_t>(number_of_warehouses), 0);
    current_objective = MAX_DOUBLE;
}

double GRASP::Evaluate(const WarehouseMask& openWarehouses, std::vector<int>* assignment) const {
    double cost = 0.0;
    bool hasOpenWarehouse = false;

    for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
        if (openWarehouses[static_cast<std::size_t>(warehouse)]) {
            cost += fixed_costs[static_cast<std::size_t>(warehouse)];
            hasOpenWarehouse = true;
        }
    }

    if (!hasOpenWarehouse) {
        return MAX_DOUBLE;
    }

    if (assignment != nullptr) {
        assignment->assign(static_cast<std::size_t>(number_of_customers), -1);
    }

    for (int customer = 0; customer < number_of_customers; ++customer) {
        double bestCost = MAX_DOUBLE;
        int bestWarehouse = -1;

        for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
            if (!openWarehouses[static_cast<std::size_t>(warehouse)]) {
                continue;
            }

            const double allocationCost =
                allocation_costs[static_cast<std::size_t>(warehouse)][static_cast<std::size_t>(customer)];
            if (allocationCost < bestCost) {
                bestCost = allocationCost;
                bestWarehouse = warehouse;
            }
        }

        cost += bestCost;
        if (assignment != nullptr) {
            (*assignment)[static_cast<std::size_t>(customer)] = bestWarehouse;
        }
    }

    return cost;
}

double GRASP::ReassignCustomers() {
    return Evaluate(warehouse_open, &customer_assignment);
}

bool GRASP::CloseWarehouse() {
    int bestWarehouse = -1;
    double bestCost = current_objective;

    for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
        if (!warehouse_open[static_cast<std::size_t>(warehouse)]) {
            continue;
        }

        WarehouseMask candidate = warehouse_open;
        candidate[static_cast<std::size_t>(warehouse)] = 0;
        const double cost = Evaluate(candidate, nullptr);

        if (cost < bestCost) {
            bestCost = cost;
            bestWarehouse = warehouse;
        }
    }

    if (bestWarehouse == -1) {
        return false;
    }

    warehouse_open[static_cast<std::size_t>(bestWarehouse)] = 0;
    current_objective = ReassignCustomers();
    return true;
}

bool GRASP::OpenWarehouse() {
    int bestWarehouse = -1;
    double bestCost = current_objective;

    for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
        if (warehouse_open[static_cast<std::size_t>(warehouse)]) {
            continue;
        }

        WarehouseMask candidate = warehouse_open;
        candidate[static_cast<std::size_t>(warehouse)] = 1;
        const double cost = Evaluate(candidate, nullptr);

        if (cost < bestCost) {
            bestCost = cost;
            bestWarehouse = warehouse;
        }
    }

    if (bestWarehouse == -1) {
        return false;
    }

    warehouse_open[static_cast<std::size_t>(bestWarehouse)] = 1;
    current_objective = ReassignCustomers();
    return true;
}

bool GRASP::OpenCloseWarehouse() {
    int bestOpen = -1;
    int bestClosed = -1;
    double bestCost = current_objective;

    for (int opening = 0; opening < number_of_warehouses; ++opening) {
        if (warehouse_open[static_cast<std::size_t>(opening)]) {
            continue;
        }

        for (int closing = 0; closing < number_of_warehouses; ++closing) {
            if (!warehouse_open[static_cast<std::size_t>(closing)]) {
                continue;
            }

            WarehouseMask candidate = warehouse_open;
            candidate[static_cast<std::size_t>(opening)] = 1;
            candidate[static_cast<std::size_t>(closing)] = 0;
            const double cost = Evaluate(candidate, nullptr);

            if (cost < bestCost) {
                bestCost = cost;
                bestOpen = opening;
                bestClosed = closing;
            }
        }
    }

    if (bestOpen == -1 || bestClosed == -1) {
        return false;
    }

    warehouse_open[static_cast<std::size_t>(bestOpen)] = 1;
    warehouse_open[static_cast<std::size_t>(bestClosed)] = 0;
    current_objective = ReassignCustomers();
    return true;
}

double GRASP::LocalSearchHeuristic(double objective) {
    current_objective = objective;

    while (CloseWarehouse() || OpenWarehouse() || OpenCloseWarehouse()) {
    }

    current_objective = ReassignCustomers();
    return current_objective;
}

double GRASP::GreedyRandomizedConstructive() {
    double currentCost = MAX_DOUBLE;

    std::fill(warehouse_open.begin(), warehouse_open.end(), 0);
    std::fill(best_assignment.begin(), best_assignment.end(), -1);

    while (true) {
        double minCost = MAX_DOUBLE;
        double maxCost = -MAX_DOUBLE;
        std::vector<double> candidateCosts(static_cast<std::size_t>(number_of_warehouses), MAX_DOUBLE);

        for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
            if (warehouse_open[static_cast<std::size_t>(warehouse)]) {
                continue;
            }

            WarehouseMask candidate = warehouse_open;
            candidate[static_cast<std::size_t>(warehouse)] = 1;
            const double cost = Evaluate(candidate, nullptr);
            candidateCosts[static_cast<std::size_t>(warehouse)] = cost;
            minCost = std::min(minCost, cost);
            maxCost = std::max(maxCost, cost);
        }

        if (minCost == MAX_DOUBLE || (currentCost != MAX_DOUBLE && minCost >= currentCost)) {
            break;
        }

        const double threshold = minCost + alpha * (maxCost - minCost);
        std::vector<int> restrictedCandidateList;
        restrictedCandidateList.reserve(static_cast<std::size_t>(number_of_warehouses));

        for (int warehouse = 0; warehouse < number_of_warehouses; ++warehouse) {
            if (!warehouse_open[static_cast<std::size_t>(warehouse)] &&
                candidateCosts[static_cast<std::size_t>(warehouse)] <= threshold) {
                restrictedCandidateList.push_back(warehouse);
            }
        }

        if (restrictedCandidateList.empty()) {
            break;
        }

        std::uniform_int_distribution<std::size_t> pick(0, restrictedCandidateList.size() - 1);
        const int chosenWarehouse = restrictedCandidateList[pick(rng)];
        warehouse_open[static_cast<std::size_t>(chosenWarehouse)] = 1;
        currentCost = ReassignCustomers();
        best_assignment = customer_assignment;
    }

    return currentCost;
}

std::vector<std::pair<int, int>> GRASP::solve(const Problem& problem) {
    initialize(problem);

    double bestCost = GreedyRandomizedConstructive();
    bestCost = LocalSearchHeuristic(bestCost);

    best_assignment = customer_assignment;
    best_warehouse_open = warehouse_open;
    current_objective = bestCost;

    std::vector<std::pair<int, int>> result;
    result.reserve(static_cast<std::size_t>(number_of_customers));

    for (int customer = 0; customer < number_of_customers; ++customer) {
        result.emplace_back(customer, best_assignment[static_cast<std::size_t>(customer)]);
    }

    return result;
}

} // namespace algorithm
