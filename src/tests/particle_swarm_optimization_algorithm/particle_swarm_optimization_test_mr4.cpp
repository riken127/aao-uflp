#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "../../misc/MParser.hpp"
#include "../../problem/Problem.hpp"
#include "../../algorithms/ParticleSwarmOptimizationAlgorithm.h"
#define OPTIMAL_SOLUTION 2756.04

bool isAlmostEqual(double a, double b, double epsilon = 1e-5) {
    return std::abs(a - b) < epsilon;
}

int main() {
    miscellaneous::MParser parser;
    try {
        Problem problem = parser.parse("../src/tests/FicheirosTeste/M/Kcapmr4.txt");

        algorithm::ParticleSwarmOptimizationAlgorithm pso(25, 100, 0.4, 0.99, 0.99);

        auto solution = pso.solve(problem);

        double totalAllocationCost = 0.0;
        double totalFixedCost = 0.0;

        std::unordered_map<int, bool> usedWarehouses;

        for (const auto& assignment : solution) {
            totalAllocationCost += problem.getCustomers()[assignment.first].getAllocationCosts()[assignment.second];
            usedWarehouses[assignment.second] = true;
        }

        for (const auto& warehouse : usedWarehouses) {
            if (warehouse.second) {
                totalFixedCost += problem.getWarehouses()[warehouse.first].getFixedCost();
            }
        }

        double totalCost = totalAllocationCost + totalFixedCost;

        std::cout << "Total Cost Found: " << totalCost << std::endl;


        if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION))
            return 0;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}