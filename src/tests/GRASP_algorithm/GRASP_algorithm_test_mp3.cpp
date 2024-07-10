#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "../../misc/MParser.hpp"
#include "../../problem/Problem.hpp"
#include "../../algorithms/GRASP.hpp"
#define OPTIMAL_SOLUTION 2498.151

bool isAlmostEqual(double a, double b, double epsilon = 1e-5) {
	std::cout << std::abs(a - b) << std::endl;
	return std::abs(a - b) < epsilon;
}

int main() {
	miscellaneous::MParser parser;
	try {
		Problem problem = parser.parse("../../../src/tests/FicheirosTeste/M/Kcapmp3.txt");
        
        double alpha = 0.1; 
        miscellaneous::AlgorithmLogger logger("GRASP_test.txt","GRASP","mp3");
		algorithm::GRASP grasp(alpha,logger);

        auto solution = grasp.solve(problem);

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