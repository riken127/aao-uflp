#include "GreedyAlgorithm.hpp"
#include <iostream>
#include <limits>
#include <algorithm> 
#include <numeric> 
#include <thread>
#include <mutex>


void algorithm::GreedyAlgorithm::solve(const Problem& problem) const {
    int num_customers = problem.getNumberOfCustomers();
    int num_warehouses = problem.getNumberOfWarehouses();
    const std::vector<Warehouse>& warehouses = problem.getWarehouses();
    const std::vector<Customer>& customers = problem.getCustomers();

    std::vector<int> allocation(num_customers, -1);
    std::vector<int> warehouse_opened(num_warehouses, 0);

    std::mutex mtx;

    for (int cust_idx = 0; cust_idx < num_customers; ++cust_idx) {
        const Customer& customer = customers[cust_idx];
        const std::vector<int>& allocation_costs = customer.getAllocationCosts();

        std::vector<std::thread> threads;
        int assigned_warehouse = -1;

        auto check_allocation = [&](int wh_idx) {
            std::lock_guard<std::mutex> lock(mtx);

            if ((warehouse_opened[wh_idx] > 0 || warehouse_opened[wh_idx] == 0) && warehouses[wh_idx].getCapacity() >= customer.getDemand()) {
                if (warehouse_opened[wh_idx] == 0) {
                    warehouse_opened[wh_idx] = warehouses[wh_idx].getCapacity();
                }
                if (assigned_warehouse == -1 ||
                    allocation_costs[wh_idx] < allocation_costs[assigned_warehouse] ||
                    (allocation_costs[wh_idx] == allocation_costs[assigned_warehouse] && warehouses[wh_idx].getFixedCost() < warehouses[assigned_warehouse].getFixedCost())) {
                    assigned_warehouse = wh_idx;
                }
            }
        };


        for (int wh_idx = 0; wh_idx < num_warehouses; ++wh_idx) {
            threads.emplace_back(check_allocation, wh_idx);
        }

        for (auto& t : threads) {
            t.join();
        }

        if (assigned_warehouse != -1) {
            allocation[cust_idx] = assigned_warehouse;
            warehouse_opened[assigned_warehouse] -= customer.getDemand();
        }
    }

    for (int cust_idx = 0; cust_idx < num_customers; ++cust_idx) {
        std::cout << "Customer " << cust_idx << " allocated to Warehouse " << allocation[cust_idx] << std::endl;
    }
}
