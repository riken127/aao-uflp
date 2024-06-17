#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <limits>

#include "../../misc/ORLibParser.hpp"
#include "../../problem/Problem.hpp"
#include "../../algorithms/HillClimbingAlgorithm.hpp"
#define OPTIMAL_SOLUTION 12979071.58143

bool isAlmostEqual(double a, double b, double epsilon = 1e-3)
{
    return std::abs(a - b) < epsilon;
}

int main()
{
    miscellaneous::ORLibParser parser;
    try
    {
        Problem problem = parser.parse("../../../src/tests/FicheirosTeste/ORLIB/ORLIB-uncap/a-c/capb.txt");
        
        int alpha = 0.1; 
        algorithm::HillClimbingAlgorithm hca;

        auto solution = hca.solve(problem);

        double totalAllocationCost = 0.0;
        double totalFixedCost = 0.0;

        std::unordered_map<int, bool> usedWarehouses;

        for (const auto &assignment : solution)
        {
            totalAllocationCost += problem.getCustomers()[assignment.first].getAllocationCosts()[assignment.second];
            usedWarehouses[assignment.second] = true;
        }

        for (const auto &warehouse : usedWarehouses)
        {
            if (warehouse.second)
            {
                totalFixedCost += problem.getWarehouses()[warehouse.first].getFixedCost();
            }
        }

        double totalCost = totalAllocationCost + totalFixedCost;
        std::cout << std::defaultfloat << std::setprecision(std::numeric_limits<double>::digits10 + 1);
        std::cout << "Total cost (full precision): " << totalCost << std::endl;
        std::cout << "Optimal cost (full precision): " << OPTIMAL_SOLUTION << std::endl;
        std::cout << "Total Allocation costs: " << totalAllocationCost << std::endl;
        std::cout << "Total Fixed costs: " << totalFixedCost << std::endl;
        std::cout << "Is optimal solution:" << isAlmostEqual(totalCost, OPTIMAL_SOLUTION) << std::endl;
        std::cout << "Difference: " << std::abs(totalCost - OPTIMAL_SOLUTION) << std::endl;

        if (isAlmostEqual(totalCost, OPTIMAL_SOLUTION))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error parsing file: " << e.what() << std::endl;
        return 1; 
    }

    return 0; 
}