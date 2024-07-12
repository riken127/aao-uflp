#include "ParticleSwarmOptimizationAlgorithm.h"
#include <limits>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <iomanip>

namespace algorithm {

struct Particle {
    std::vector<bool> position;
    std::vector<double> velocity;
    std::vector<bool> bestPosition;
    double bestCost;
};

double ParticleSwarmOptimizationAlgorithm::calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const {
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

void ParticleSwarmOptimizationAlgorithm::getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const {
    // Initially open all warehouses
    openWarehouses.assign(problem.getNumberOfWarehouses(), true);
}

void ParticleSwarmOptimizationAlgorithm::getBestNeighbor(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& bestNeighbor) const {
    double bestCost = std::numeric_limits<double>::max();
    bestNeighbor = currentSolution;

    // Switch operation
    for (size_t i = 0; i < currentSolution.size(); ++i) {
        std::vector<bool> neighbor = currentSolution;
        neighbor[i] = !neighbor[i]; // Toggle the state of the ith warehouse

        double neighborCost = calculateCost(problem, neighbor);
        if (neighborCost < bestCost) {
            bestCost = neighborCost;
            bestNeighbor = neighbor;
        }
    }

    // Swap operation
    for (size_t i = 0; i < currentSolution.size(); ++i) {
        for (size_t j = i + 1; j < currentSolution.size(); ++j) {
            if (currentSolution[i] != currentSolution[j]) {
                std::vector<bool> neighbor = currentSolution;
                std::swap(neighbor[i], neighbor[j]); // Swap the state of the ith and jth warehouse

                double neighborCost = calculateCost(problem, neighbor);
                if (neighborCost < bestCost) {
                    bestCost = neighborCost;
                    bestNeighbor = neighbor;
                }
            }
        }
    }
}

void ParticleSwarmOptimizationAlgorithm::localSearch(const Problem& problem, std::vector<bool>& solution) const {
    double currentCost = calculateCost(problem, solution);
    bool localOptimum = false;

    while (!localOptimum) {
        std::vector<bool> neighborSolution;
        getBestNeighbor(problem, solution, neighborSolution);

        double neighborCost = calculateCost(problem, neighborSolution);

        if (neighborCost < currentCost) {
            solution = neighborSolution;
            currentCost = neighborCost;
        } else {
            localOptimum = true;
        }
    }
}

std::vector<std::pair<int, int>> ParticleSwarmOptimizationAlgorithm::solve(const Problem& problem) const {
    std::vector<Particle> swarm(swarmSize);
    std::vector<bool> globalBestPosition;
    double globalBestCost = std::numeric_limits<double>::max();

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (auto& particle : swarm) {
        getInitialSolution(problem, particle.position);
        particle.velocity.resize(problem.getNumberOfWarehouses(), 0.0);
        particle.bestPosition = particle.position;
        particle.bestCost = calculateCost(problem, particle.position);

        if (particle.bestCost < globalBestCost) {
            globalBestCost = particle.bestCost;
            globalBestPosition = particle.bestPosition;
        }
    }

    for (int iter = 0; iter < maxIterations; ++iter) {
        for (auto& particle : swarm) {
            for (size_t i = 0; i < particle.position.size(); ++i) {
                double r1 = distribution(generator);
                double r2 = distribution(generator);

                particle.velocity[i] = inertiaWeight * particle.velocity[i] +
                    cognitiveCoefficient * r1 * (particle.bestPosition[i] - particle.position[i]) +
                    socialCoefficient * r2 * (globalBestPosition[i] - particle.position[i]);

                if (distribution(generator) < 1 / (1 + exp(-particle.velocity[i]))) {
                    particle.position[i] = !particle.position[i];
                }
            }

            double currentCost = calculateCost(problem, particle.position);
            if (currentCost < particle.bestCost) {
                particle.bestCost = currentCost;
                particle.bestPosition = particle.position;
            }

            if (particle.bestCost < globalBestCost) {
                globalBestCost = particle.bestCost;
                globalBestPosition = particle.bestPosition;
            }
        }

        std::cout << "Iteration " << iter + 1 << ": Best Cost = " << std::setprecision(20) << globalBestCost << std::endl;
    }

    localSearch(problem, globalBestPosition);

    std::vector<std::pair<int, int>> assignments;
    const auto& customers = problem.getCustomers();

    for (size_t i = 0; i < customers.size(); ++i) {
        const auto& allocationCosts = customers[i].getAllocationCosts();
        int bestWarehouse = -1;
        double minCost = std::numeric_limits<double>::max();

        for (size_t j = 0; j < globalBestPosition.size(); ++j) {
            if (globalBestPosition[j] && allocationCosts[j] < minCost) {
                minCost = allocationCosts[j];
                bestWarehouse = static_cast<int>(j);
            }
        }

        assignments.emplace_back(static_cast<int>(i), bestWarehouse);
    }

    return assignments;
}

}
