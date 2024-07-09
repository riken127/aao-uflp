#include "VariableNeighborhoodSearchAlgorithm.h"
#include <limits>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iomanip>

namespace algorithm {

double VariableNeighborhoodSearchAlgorithm::calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const {
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

void VariableNeighborhoodSearchAlgorithm::getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const {
    openWarehouses.assign(problem.getNumberOfWarehouses(), true);
}

void VariableNeighborhoodSearchAlgorithm::shake(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& shakenSolution, int k) const {
    shakenSolution = currentSolution;
    for (int i = 0; i < k; ++i) {
        size_t index = rand() % currentSolution.size();
        shakenSolution[index] = !shakenSolution[index];
    }
}

void VariableNeighborhoodSearchAlgorithm::localSearch(const Problem& problem, std::vector<bool>& solution) const {
    bool improvement = true;

    while (improvement) {
        improvement = false;
        double currentCost = calculateCost(problem, solution);

        for (size_t i = 0; i < solution.size(); ++i) {
            std::vector<bool> neighbor = solution;
            neighbor[i] = !neighbor[i];
            double neighborCost = calculateCost(problem, neighbor);

            if (neighborCost < currentCost) {
                solution = neighbor;
                currentCost = neighborCost;
                improvement = true;
                break;
            }
        }
    }
}

std::vector<std::pair<int, int>> VariableNeighborhoodSearchAlgorithm::solve(const Problem& problem) const {
    std::vector<bool> currentSolution;
    getInitialSolution(problem, currentSolution);

    double currentCost = calculateCost(problem, currentSolution);
    bool localOptimum = false;

    int iteration = 0;

    while (iteration < maxIterations) {
        ++iteration;

        for (int k = 1; k <= kMax; ++k) {
            std::vector<bool> shakenSolution;
            shake(problem, currentSolution, shakenSolution, k);
            localSearch(problem, shakenSolution);

            double shakenCost = calculateCost(problem, shakenSolution);

            if (shakenCost < currentCost) {
                currentSolution = shakenSolution;
                currentCost = shakenCost;
                break;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Iteration " << iteration << " time: " << std::fixed << std::setprecision(2) << " New total cost: " << currentCost << std::endl;
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
