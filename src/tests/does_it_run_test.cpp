#include <iostream>
#include <unordered_map>
#include "../misc/ORLibParser.hpp"
#include "../problem/Problem.hpp"
#include "../algorithms/CrowSearchAlgorithm.hpp"

int main() {
    // Parse the file and gather information
    miscellaneous::ORLibParser parser;
    try {
        Problem problem = parser.parse("/mnt/c/Users/henri/Source/Repos/aao-uflp/src/tests/FicheirosTeste/ORLIB/ORLIB-uncap/130/cap131.txt");

        // Create an instance of the CrowSearchAlgorithm
        algorithm::CrowSearchAlgorithm csa;

        // Solve the problem using the CrowSearchAlgorithm
        auto solution = csa.solve(problem);

        // Calculate and print the total fixed cost of warehouses
        double totalAllocationCost = 0.0;
        double totalFixedCost = 0.0;

        // To avoid counting fixed costs multiple times, use a set to keep track of which warehouses are used
        std::unordered_map<int, bool> usedWarehouses;

        for (const auto& assignment : solution) {
            totalAllocationCost += problem.getCustomers()[assignment.first].getAllocationCosts()[assignment.second];
            usedWarehouses[assignment.second] = true;
        }

        // Sum up the fixed costs for all used warehouses
        for (const auto& warehouse : usedWarehouses) {
            if (warehouse.second) {
                totalFixedCost += problem.getWarehouses()[warehouse.first].getFixedCost();
            }
        }

        double totalCost = totalAllocationCost + totalFixedCost;
        std::cout << "Total cost: " << totalCost << std::endl;
        std::cout << "Total Allocation costs: " << totalAllocationCost << std::endl;
        std::cout << "Total Fixed costs: " << totalFixedCost << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing file: " << e.what() << std::endl;
        return 1; // Failure
    }

    return 0; // Success
}