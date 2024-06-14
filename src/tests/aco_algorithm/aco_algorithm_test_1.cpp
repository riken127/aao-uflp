#include "../../problem/Problem.hpp"
#include "../../algorithms/Aco.hpp"
#include <iostream>

int main() {
	Problem problem3(3, 2); // 3 customers, 2 warehouses
	problem3.addWarehouse(Warehouse(100, 10));
	problem3.addWarehouse(Warehouse(200, 20));
	problem3.addCustomer(Customer(50, { 5, 8 }));
	problem3.addCustomer(Customer(30, { 4, 6 }));
	problem3.addCustomer(Customer(70, { 6, 9 }));
	// Create an instance of the GeneticAlgorithm
	auto aco = algorithm::ACO(100,1,1,0.5,4);

	// Solve the problem using the GeneticAlgorithm
	auto solution = aco.solve(problem3);

	// Print the solution
	std::cout << "Solution:" << std::endl;
	for (const auto& assignment : solution) {
		std::cout << "Customer " << assignment.first + 1 << " assigned to Warehouse " << assignment.second + 1 << std::endl;
	}

	return 0;
}