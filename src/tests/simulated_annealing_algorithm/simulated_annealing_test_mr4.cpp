#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "../../problem/Problem.hpp"
#include "../../algorithms/SimulatedAnnealingAlgorithm.h"
#include "../../misc/MParser.hpp"
#define OPTIMAL_SOLUTION 2756.04

bool isAlmostEqual(double a, double b, double epsilon = 1e-3) {
    std::cout << std::abs(a - b) << std::endl;
    return std::abs(a - b) < epsilon;
}

int main() {
    miscellaneous::MParser parser;
    try {
        Problem problem = parser.parse("../../../src/tests/FicheirosTeste/M/Kcapmr4.txt");
        algorithm::SimulatedAnnealingAlgorithm simulated_annealing_algorithm(1000
            , 0.1, 0.9, 200);
        auto solution = simulated_annealing_algorithm.solve(problem);

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
        if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION))
            std::cout << "Optimal solution found!" << std::endl;
        if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing file: " << e.what() << std::endl;
        return 1; // Failure
    }

    return 0; // Success
}