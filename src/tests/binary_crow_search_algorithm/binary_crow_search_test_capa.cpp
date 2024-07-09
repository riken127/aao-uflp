#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include "../../misc/ORLibParser.hpp"
#include "../../problem/Problem.hpp"
#include "../../algorithms/CrowSearchAlgorithm.hpp"
#define OPTIMAL_SOLUTION 17156454.47830

bool isAlmostEqual(double a, double b, double epsilon = 1e-3)
{
	return std::abs(a - b) < epsilon;
}

int main()
{
	miscellaneous::ORLibParser parser;
	miscellaneous::AlgorithmLogger logger("binary_crow_search_test_capa.txt", "BinaryCrowSearch", "capa");
	try
	{
		Problem problem = parser.parse("../src/tests/FicheirosTeste/ORLIB/ORLIB-uncap/a-c/capa.txt");
		algorithm::CrowSearchAlgorithm csa(400, 0.1, 80000, logger);

		auto solution = csa.solve(problem);

		double totalAllocationCost = 0.0;
		double totalFixedCost = 0.0;

		std::unordered_map<int, bool> usedWarehouses;

		for (const auto& assignment : solution)
		{
			totalAllocationCost += problem.getCustomers()[assignment.first].getAllocationCosts()[assignment.second];
			usedWarehouses[assignment.second] = true;
		}

		for (const auto& warehouse : usedWarehouses)
		{
			if (warehouse.second)
			{
				totalFixedCost += problem.getWarehouses()[warehouse.first].getFixedCost();
			}
		}

		double totalCost = totalAllocationCost + totalFixedCost;
		if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION))
			std::cout << "Optimal solution found!" << std::endl;
		if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error parsing file: " << e.what() << std::endl;
		return 1; // Failure
	}

	return 0; // Success
}
