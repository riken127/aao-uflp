#include "TabuSearchAlgorithm.hpp"
#include <algorithm>
#include <iostream>
#include <limits>

namespace algorithm {

    std::vector<std::pair<int, int>> TabuSearchAlgorithm::solve(const Problem& problem) const {
        // Implementação do algoritmo Tabu Search
        std::vector<std::pair<int, int>> bestSolution = generateInitialSolution(problem);
        double bestCost = calculateCost(bestSolution, problem);

        std::unordered_set<std::vector<std::pair<int, int>>, VectorPairHash> tabuList;
        tabuList.insert(bestSolution);

        // Parâmetros do algoritmo
        int maxIterations = 1000;
        int tabuTenure = 10;

        for (int iteration = 0; iteration < maxIterations; ++iteration) {
            auto neighbors = generateNeighbors(bestSolution);
            std::vector<std::pair<int, int>> bestNeighbor;
            double bestNeighborCost = std::numeric_limits<double>::max();

            for (const auto& neighbor : neighbors) {
                if (tabuList.find(neighbor) == tabuList.end()) {
                    double neighborCost = calculateCost(neighbor, problem);
                    if (neighborCost < bestNeighborCost) {
                        bestNeighbor = neighbor;
                        bestNeighborCost = neighborCost;
                    }
                }
            }

            if (bestNeighborCost < bestCost) {
                bestSolution = bestNeighbor;
                bestCost = bestNeighborCost;
            }

            tabuList.insert(bestNeighbor);
            if (tabuList.size() > tabuTenure) {
                tabuList.erase(tabuList.begin());
            }
        }

        return bestSolution;
    }

    std::vector<std::pair<int, int>> TabuSearchAlgorithm::generateInitialSolution(const Problem& problem) const {
        int numFacilities = problem.getNumWarehouses();
        int numClients = problem.getNumCustomers();

        std::vector<std::pair<int, int>> solution;
        for (int i = 0; i < numClients; ++i) {
            solution.emplace_back(i, i % numFacilities);
        }

        return solution;
    }

    std::vector<std::vector<std::pair<int, int>>> TabuSearchAlgorithm::generateNeighbors(const std::vector<std::pair<int, int>>& solution) const {
        std::vector<std::vector<std::pair<int, int>>> neighbors;
        
        for (size_t i = 0; i < solution.size(); ++i) {
            for (size_t j = 0; j < solution.size(); ++j) {
                if (i != j) {
                    std::vector<std::pair<int, int>> neighbor = solution;
                    std::swap(neighbor[i], neighbor[j]);
                    neighbors.push_back(neighbor);
                }
            }
        }

        return neighbors;
    }

    double TabuSearchAlgorithm::calculateCost(const std::vector<std::pair<int, int>>& solution, const Problem& problem) const {
        double totalCost = 0.0;
        for (const auto& assignment : solution) {
            int customerIndex = assignment.first;
            int warehouseIndex = assignment.second;

            totalCost += problem.getCost(customerIndex, warehouseIndex);
        }

        return totalCost;
    }
}
