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
        if (openWarehouses[i]) {
            totalCost += warehouses[i].getFixedCost();
        }
    }

    for (const auto& customer : customers) {
        double minCost = std::numeric_limits<double>::max();
        const auto& allocationCosts = customer.getAllocationCosts();

        for (size_t i = 0; i < openWarehouses.size(); ++i) {
            if (openWarehouses[i]) {
                minCost = std::min(minCost, allocationCosts[i]);
            }
        }

        totalCost += minCost;
    }

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
        std::vector<bool> neighbor = currentSolution;
        neighbor[i] = !neighbor[i]; // Toggle the state of the ith warehouse

        double neighborCost = calculateCost(problem, neighbor);
        if (neighborCost < bestCost) {
            bestCost = neighborCost;
            bestNeighbor = neighbor;
        }
    }
}

std::vector<std::pair<int, int>> HillClimbingAlgorithm::solve(const Problem& problem) const {
    std::vector<bool> currentSolution;
    getInitialSolution(problem, currentSolution);

    double currentCost = calculateCost(problem, currentSolution);
    bool localOptimum = false;

    int iteration = 0;

    while (!localOptimum) {
        ++iteration;

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<bool> neighborSolution;
        getBestNeighbor(problem, currentSolution, neighborSolution);
    
        double neighborCost = calculateCost(problem, neighborSolution);
        
        if (neighborCost < currentCost) {
            currentSolution = neighborSolution;
            currentCost = neighborCost;
        } else {
            localOptimum = true;
        }
    
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
    
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

    return assignments;
}

} // namespace algorithm
