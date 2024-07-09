// SimulatedAnnealingAlgorithm.cpp

#include "SimulatedAnnealingAlgorithm.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace algorithm;

double SimulatedAnnealingAlgorithm::calculateCost(const std::vector<int>& assignment, const Problem& problem) const {
    double total_cost = 0.0;
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    std::vector<bool> facilities_open(warehouses.size(), false);

    for (int j = 0; j < assignment.size(); ++j) {
        int warehouse_index = assignment[j];
        total_cost += customers[j].getAllocationCosts()[warehouse_index];
        if (!facilities_open[warehouse_index]) {
            total_cost += warehouses[warehouse_index].getFixedCost();
            facilities_open[warehouse_index] = true;
        }
    }

    return total_cost;
}

SimulatedAnnealingAlgorithm::Solution SimulatedAnnealingAlgorithm::generateInitialSolution(const Problem& problem) const {
    Solution initial_solution;
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();

    initial_solution.assignment.resize(customers.size());

    // Simple greedy heuristic: Assign each customer to the cheapest warehouse
    for (int j = 0; j < customers.size(); ++j) {
        int best_warehouse = 0;
        double best_cost = customers[j].getAllocationCosts()[0];
        for (int i = 1; i < warehouses.size(); ++i) {
            double cost = customers[j].getAllocationCosts()[i];
            if (cost < best_cost) {
                best_warehouse = i;
                best_cost = cost;
            }
        }
        initial_solution.assignment[j] = best_warehouse;
    }

    initial_solution.total_cost = calculateCost(initial_solution.assignment, problem);
    return initial_solution;
}

SimulatedAnnealingAlgorithm::Solution SimulatedAnnealingAlgorithm::generateNeighbor(const Solution& current_solution, const Problem& problem) const {
    RandomGenerator random;
    Solution new_solution = current_solution;

    // Choose a move type: 0 = swap, 1 = insert
    int move_type = random.getRandomInt(2);

    if (move_type == 0) {
        // Swap two random customers
        int customer1 = random.getRandomInt(problem.getNumberOfCustomers());
        int customer2 = random.getRandomInt(problem.getNumberOfCustomers());
        while (customer1 == customer2) {
            customer2 = random.getRandomInt(problem.getNumberOfCustomers());
        }
        std::swap(new_solution.assignment[customer1], new_solution.assignment[customer2]);
    } else if (move_type == 1) {
        // Insert a customer to a different warehouse
        int customer = random.getRandomInt(problem.getNumberOfCustomers());
        int new_warehouse = random.getRandomInt(problem.getNumberOfWarehouses());
        new_solution.assignment[customer] = new_warehouse;
    }

    localSearch(new_solution, problem, 6);
    return new_solution;
}

void SimulatedAnnealingAlgorithm::localSearch(Solution& solution, const Problem& problem, int tabu_tenure) const {
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    std::unordered_set<int> tabu_list;
    int iterations_without_improvement = 0;

    while (iterations_without_improvement < max_iterations_without_improvement) {
        bool found_improvement = false;

        for (int j = 0; j < customers.size(); ++j) {
            int current_warehouse = solution.assignment[j];
            double current_cost = customers[j].getAllocationCosts()[current_warehouse];
            if (tabu_list.find(current_warehouse) == tabu_list.end()) {
                current_cost += warehouses[current_warehouse].getFixedCost();
            }

            int best_warehouse = current_warehouse;
            double best_cost = current_cost;

            for (int i = 0; i < warehouses.size(); ++i) {
                if (i != current_warehouse && tabu_list.find(i) == tabu_list.end()) {
                    double new_cost = customers[j].getAllocationCosts()[i] + warehouses[i].getFixedCost();
                    if (new_cost < best_cost) {
                        best_warehouse = i;
                        best_cost = new_cost;
                        found_improvement = true;
                    }
                }
            }

            if (found_improvement) {
                solution.assignment[j] = best_warehouse;
                tabu_list.insert(best_warehouse);
                if (tabu_list.size() > tabu_tenure) {
                    tabu_list.erase(tabu_list.begin());
                }
                iterations_without_improvement = 0;
            } else {
                iterations_without_improvement++;
            }
        }

        if (!found_improvement) {
            iterations_without_improvement++;
        }
    }

    solution.total_cost = calculateCost(solution.assignment, problem);
}

SimulatedAnnealingAlgorithm::Solution SimulatedAnnealingAlgorithm::adaptivePerturbation(const Solution& current_solution, const Problem& problem, int iteration) const {
    RandomGenerator random;
    Solution new_solution = current_solution;

    int num_customers = problem.getNumberOfCustomers();
    int perturbation_size = (iteration % 2 == 0) ? num_customers / 3 : num_customers / 5;

    std::unordered_set<int> perturbed_customers;
    while (perturbed_customers.size() < perturbation_size) {
        perturbed_customers.insert(random.getRandomInt(num_customers));
    }

    for (int client : perturbed_customers) {
        new_solution.assignment[client] = random.getRandomInt(problem.getNumberOfWarehouses());
    }

    return new_solution;
}

std::vector<std::pair<int, int>> SimulatedAnnealingAlgorithm::solve(const Problem& problem) const {
    RandomGenerator random;
    int num_warehouses = problem.getNumberOfWarehouses();
    int num_customers = problem.getNumberOfCustomers();

    Solution initial_solution = generateInitialSolution(problem);
    Solution current_solution = initial_solution;
    Solution best_solution = current_solution;

    double temperature = initial_temperature;
    int iteration = 0;

    while (temperature > final_temperature) {
        for (int i = 0; i < iterations_per_temp; ++i) {
            Solution new_solution = generateNeighbor(current_solution, problem);
            new_solution.total_cost = calculateCost(new_solution.assignment, problem);
            localSearch(new_solution, problem, 6);

            double delta_cost = new_solution.total_cost - current_solution.total_cost;

            if (delta_cost < 0 || std::exp(-delta_cost / temperature) > random.getRandom()) {
                current_solution = new_solution;
            }

            if (current_solution.total_cost < best_solution.total_cost) {
                best_solution = current_solution;
                std::cout << "New Best solution found: " << best_solution.total_cost << std::endl;
            }
        }

        // Geometric cooling schedule
        temperature *= cooling_rate;

        if (++iteration % 30 == 0) {
            current_solution = adaptivePerturbation(best_solution, problem, iteration);
            current_solution.total_cost = calculateCost(current_solution.assignment, problem);
        }
    }

    std::vector<std::pair<int, int>> result(num_customers);
    for (int j = 0; j < num_customers; ++j) {
        result[j] = std::make_pair(j, best_solution.assignment[j]);
    }

    return result;
}
