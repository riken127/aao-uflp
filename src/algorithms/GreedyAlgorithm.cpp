#include "GreedyAlgorithm.hpp"
#include <iostream>
#include <limits>
#include <algorithm> 
#include <numeric> 
#include <thread>
#include <mutex>
/**
* @brief Solves the UFLP problem using a Greedy Algorithm
* @param problem The problem to be solved
* @return A vector of pairs, where the first element of the pair is the index of the customer and the second element is the index of the warehouse
* @details The algorithm works as follows:
* 1. For each customer, it calculates the cost of allocating the customer to each warehouse
* 2. It then allocates the customer to the warehouse with the minimum cost, taking into account the fixed cost of the warehouse and the capacity constraints
* 3. If the warehouse has not been opened yet, it opens the warehouse
* 4. It repeats the process for all customers
* @see Problem
* @see Warehouse
* @see Customer
*/
std::vector<std::pair<int, int>> algorithm::GreedyAlgorithm::solve(const Problem& problem) const {
	/*const std::vector<Warehouse>& warehouses = problem.getWarehouses();
	const std::vector<Customer>& customers = problem.getCustomers();
	int num_warehouses = warehouses.size();
	int num_customers = customers.size();

	std::vector<std::pair<int, int>> allocation;

	std::vector<int> warehouse_capacity(num_warehouses, 0);

	std::vector<bool> warehouse_opened(num_warehouses, false);

	for (int i = 0; i < num_customers; ++i) {
		const Customer& customer = customers[i];
		//const std::vector<int>allocation_costs(customer.getAllocationCosts(), 0);

		int min_cost = std::numeric_limits<int>::max();
		int min_warehouse = -1;

		for (int j = 0; j < num_warehouses; ++j) {
			if (!warehouse_opened[j]) {
				if (warehouses[j].getCapacity() >= customer.getDemand()) {
					min_cost = 0;
					min_warehouse = j;
					break;
				}
			}
			else {
				int total_cost = allocation_costs[j] + warehouses[j].getFixedCost();
				if (total_cost < min_cost && warehouse_capacity[j] + customer.getDemand() <= warehouses[j].getCapacity()) {
					min_cost = total_cost;
					min_warehouse = j;
				}
			}
		}

		if (min_warehouse != -1) {
			allocation.push_back(std::make_pair(i, min_warehouse));
			warehouse_capacity[min_warehouse] += customer.getDemand();
			if (!warehouse_opened[min_warehouse]) {
				warehouse_opened[min_warehouse] = true;
			}
		}
	}
	return allocation;*/
}
