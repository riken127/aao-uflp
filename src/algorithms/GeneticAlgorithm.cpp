#include "GeneticAlgorithm.hpp"
#include <vector>
#include <algorithm>


    std::vector<algorithm::GeneticAlgorithm::Assignment> algorithm::GeneticAlgorithm::calculateInitialAssignments(
        const std::vector<Customer>& customers, 
        const std::vector<Warehouse>& warehouses) const {
        
        std::vector<GeneticAlgorithm::Assignment> initial_assignments;
        for (int c_idx = 0; c_idx < customers.size(); ++c_idx) {
            const auto& customer = customers[c_idx];
            const auto& costs = customer.getAllocationCosts();

            for (int w_idx = 0; w_idx < warehouses.size(); ++w_idx) {
                initial_assignments.push_back({c_idx, w_idx, costs[w_idx]});
            }
        }

        return initial_assignments;
    }

    void algorithm::GeneticAlgorithm::sortAssignmentsByCost(std::vector<GeneticAlgorithm::Assignment>& assignments) const {
        std::sort(assignments.begin(), assignments.end(), [](const GeneticAlgorithm::Assignment& a, const GeneticAlgorithm::Assignment& b) {
            return a.cost < b.cost;
        });
    }

    std::vector<int> algorithm::GeneticAlgorithm::findBestWarehouses(
        const std::vector<Assignment>& assignments, 
        const std::vector<Warehouse>& warehouses, 
        int num_customers) const {

        std::vector<int> warehouse_usage(warehouses.size(), 0);
        std::vector<int> warehouse_opened(warehouses.size(), 0);

        for (const auto& assignment : assignments) {
            int w_idx = assignment.warehouse_idx;
            warehouse_opened[w_idx] = 1;
        }

        return warehouse_opened;
    }

    std::vector<std::pair<int, int>> algorithm::GeneticAlgorithm::solve(const Problem& problem) const {
        const auto& customers = problem.getCustomers();
        const auto& warehouses = problem.getWarehouses();

        // Step 1: Calculate initial assignments based on cost
        std::vector<Assignment> assignments = calculateInitialAssignments(customers, warehouses);

        // Step 2: Sort assignments by cost
        sortAssignmentsByCost(assignments);

        // Step 3: Find the best warehouses to open
        std::vector<int> best_warehouses = findBestWarehouses(assignments, warehouses, problem.getNumberOfCustomers());

        // Step 4: Make final assignments based on opened warehouses
        std::vector<std::pair<int, int>> final_assignments;
        std::vector<int> warehouse_usage(warehouses.size(), 0);
        
        for (const auto& assignment : assignments) {
            int c_idx = assignment.customer_idx;
            int w_idx = assignment.warehouse_idx;
            
            if (best_warehouses[w_idx] && warehouse_usage[w_idx] + customers[c_idx].getDemand() <= warehouses[w_idx].getCapacity()) {
                final_assignments.emplace_back(c_idx, w_idx);
                warehouse_usage[w_idx] += customers[c_idx].getDemand();
            }
        }

        return final_assignments;
    }
