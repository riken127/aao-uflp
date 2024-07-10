#include "HillClimbingAlgorithm.hpp"
#include <limits>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iomanip>

namespace algorithm {

double HillClimbingAlgorithm::calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const {
    double totalCost = 0.0;

    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();

    for (size_t i = 0; i < openWarehouses.size(); ++i) {
        num_comparisons++;
        num_comparisons++;
        if (openWarehouses[i]) {
            totalCost += warehouses[i].getFixedCost();
        }
    }
    num_comparisons++;

    curr_total_assignment_cost = 0;
    for (const auto& customer : customers) {
        num_comparisons++;
        double minCost = std::numeric_limits<double>::max();
        const auto& allocationCosts = customer.getAllocationCosts();

        for (size_t i = 0; i < openWarehouses.size(); ++i) {
            num_comparisons++;
            num_comparisons++;
            if (openWarehouses[i]) {
                minCost = std::min(minCost, allocationCosts[i]);
            }
        }

        curr_total_assignment_cost += minCost;
        totalCost += minCost;
    }
    num_comparisons++;

    return totalCost;
}

void HillClimbingAlgorithm::getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const {
    // Initially open all warehouses
    openWarehouses.assign(problem.getNumberOfWarehouses(), true);
}

void HillClimbingAlgorithm::getBestNeighbor(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& bestNeighbor) const {
    double bestCost = std::numeric_limits<double>::max();
    bestNeighbor = currentSolution;

    for (size_t i = 0; i < currentSolution.size(); ++i) {
        num_comparisons++;
        std::vector<bool> neighbor = currentSolution;
        neighbor[i] = !neighbor[i]; // Toggle the state of the ith warehouse

        double neighborCost = calculateCost(problem, neighbor);
        num_comparisons++;
        if (neighborCost < bestCost) {
            bestCost = neighborCost;
            bestNeighbor = neighbor;
        }
    }
    num_comparisons++;
}

std::vector<std::pair<int, int>> HillClimbingAlgorithm::solve(const Problem& problem) const {
    std::vector<bool> currentSolution;
    getInitialSolution(problem, currentSolution);

    double currentCost = calculateCost(problem, currentSolution);
    bool localOptimum = false;

    int iteration = 0;

    while (!localOptimum) {
        num_comparisons++;
        ++iteration;
        num_iterations++;
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<bool> neighborSolution;
        getBestNeighbor(problem, currentSolution, neighborSolution);
    
        double neighborCost = calculateCost(problem, neighborSolution);

        num_comparisons++;
        if (neighborCost < currentCost) {
            currentSolution = neighborSolution;
            currentCost = neighborCost;
        } else {
            num_comparisons++;
            localOptimum = true;
        }

        logger.logGeneral(num_iterations, num_comparisons, -1, -1, -1, currentCost, curr_total_assignment_cost);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        logger.logHillClimbing(num_iterations, num_comparisons, currentCost, currentSolution, elapsed.count());

        std::cout << "Iteration " << iteration << " time: " << std::fixed << std::setprecision(2) << elapsed.count() << "s. New total cost: " << currentCost << std::endl;
    }

    std::vector<std::pair<int, int>> assignments;
    const auto& customers = problem.getCustomers();

    for (size_t i = 0; i < customers.size(); ++i) {
        const auto& allocationCosts = customers[i].getAllocationCosts();
        int bestWarehouse = -1;
        double minCost = std::numeric_limits<double>::max();

        for (size_t j = 0; j < currentSolution.size(); ++j) {
            if (currentSolution[j] && allocationCosts[j] < minCost) {
                minCost = allocationCosts[j];
                bestWarehouse = static_cast<int>(j);
            }
        }

        assignments.emplace_back(static_cast<int>(i), bestWarehouse);
    }

    logger.saveGeneralLogToFile();
    logger.saveHillClimbingLogToFile();
    return assignments;
}

} // namespace algorithm