#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../algorithms/GreedyAlgorithm.hpp"
#include "../../problem/Problem.hpp"

int main() {
    Problem problem(4, 2);

    problem.addWarehouse(Warehouse(200, 15));
    problem.addWarehouse(Warehouse(300, 25));

    problem.addCustomer(Customer(90, { 18, 22 }));
    problem.addCustomer(Customer(120, { 20, 25 }));
    problem.addCustomer(Customer(100, { 16, 20 }));
    problem.addCustomer(Customer(110, { 22, 27 }));

    std::vector<int> expectedSolution = { 30, 50 };
    algorithm::GreedyAlgorithm greedy;
    std::vector<std::pair<int, int>> solution = greedy.solve(problem);

    std::unordered_map<int, int> totalFixedCost;
    for (const auto& allocation : solution) {
        int warehouseIndex = allocation.second;
        int fixedCost = problem.getWarehouses()[warehouseIndex].getFixedCost();
        totalFixedCost[warehouseIndex] += fixedCost;
    }

    // Display the total fixed cost for each warehouse
    for (const auto& pair : totalFixedCost) {
        std::cout << "Warehouse " << pair.first << ": Total Fixed Cost = " << pair.second << std::endl;
    }

    // Compare the total fixed cost for each warehouse to the expected fixed cost
    for (size_t i = 0; i < expectedSolution.size(); ++i) {
        if (totalFixedCost[i] != expectedSolution[i]) {
            return 1;
        }
    }

    return 0;
}
