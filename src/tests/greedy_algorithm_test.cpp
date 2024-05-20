#include <iostream>
#include <vector>
#include "../algorithms/GreedyAlgorithm.hpp"
#include "../problem/Problem.hpp"

int main() {
    Problem problem(5, 3); 

    problem.addWarehouse(Warehouse(200, 15));
    problem.addWarehouse(Warehouse(250, 20));
    problem.addWarehouse(Warehouse(150, 10));

    problem.addCustomer(Customer(80, { 18, 28, 22 }));
    problem.addCustomer(Customer(100, { 20, 30, 25 }));
    problem.addCustomer(Customer(70, { 16, 26, 20 }));
    problem.addCustomer(Customer(120, { 22, 32, 27 }));
    problem.addCustomer(Customer(90, { 14, 24, 18 })); 

    /**
    * Resultado esperado:
    * - Warehouse 0: C0, C1, C2
    * - Warehouse 1: Nada
    * - Warehouse 2: C3, C4
    */

    std::vector<int> expectedSolution = { 0, 0, 1 };
    algorithm::GreedyAlgorithm greedy;
    greedy.solve(problem);
    return 0;
}
