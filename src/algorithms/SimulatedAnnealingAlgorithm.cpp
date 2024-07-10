#include "SimulatedAnnealingAlgorithm.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_set>

/**
 * Calculates the total cost of the given assignment.
 */
double algorithm::SimulatedAnnealingAlgorithm::calculateCost(const std::vector<int>& assignment, const Problem& problem) const {
    double total_cost = 0.0;
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    std::vector<bool> facilities_open(warehouses.size(), false);

    for (int j = 0; j < assignment.size(); ++j) {
        num_comparisons++;
        int warehouse_index = assignment[j];
        total_cost += customers[j].getAllocationCosts()[warehouse_index];
        num_comparisons++;
        if (!facilities_open[warehouse_index]) {
            total_cost += warehouses[warehouse_index].getFixedCost();
            facilities_open[warehouse_index] = true;
        }
    }
    num_comparisons++;

    return total_cost;
}

/**
 * Generates a neighboring solution by randomly perturbing a small subset of the current solution.
 */
algorithm::SimulatedAnnealingAlgorithm::Solution algorithm::SimulatedAnnealingAlgorithm::generateNeighbor(const Solution& current_solution, const Problem& problem) const {
    RandomGenerator random;
    Solution new_solution = current_solution;

    int num_perturbations = std::min(problem.getNumberOfCustomers() / 10, 25);
    std::unordered_set<int> perturbed_customers;
    while (perturbed_customers.size() < num_perturbations) {
        num_comparisons++;
        perturbed_customers.insert(random.getRandomInt(problem.getNumberOfCustomers()));
    }
    num_comparisons++;

    for (int client : perturbed_customers) {
        num_comparisons++;
        new_solution.assignment[client] = random.getRandomInt(problem.getNumberOfWarehouses());
    }
    num_comparisons++;

    localSearch(new_solution, problem, 6);
    return new_solution;
}

/**
 * Performs a local search to refine the given solution using a tabu list to avoid cycles.
 */
void algorithm::SimulatedAnnealingAlgorithm::localSearch(Solution& solution, const Problem& problem, int tabu_tenure) const {
    const auto& warehouses = problem.getWarehouses();
    const auto& customers = problem.getCustomers();
    std::unordered_set<int> tabu_list;
    int iterations_without_improvement = 0;

    while (iterations_without_improvement < 20) {
        num_comparisons++;
        bool found_improvement = false;

        for (int j = 0; j < customers.size(); ++j) {
            num_comparisons++;

            int current_warehouse = solution.assignment[j];
            double current_cost = customers[j].getAllocationCosts()[current_warehouse];

            num_comparisons++;
            if (tabu_list.find(current_warehouse) == tabu_list.end()) {
                current_cost += warehouses[current_warehouse].getFixedCost();
            }

            int best_warehouse = current_warehouse;
            double best_cost = current_cost;

            for (int i = 0; i < warehouses.size(); ++i) {
                num_comparisons++;
                num_comparisons++;
                if (i != current_warehouse && tabu_list.find(i) == tabu_list.end()) {
                    num_comparisons++;
                    double new_cost = customers[j].getAllocationCosts()[i] + warehouses[i].getFixedCost();
                    num_comparisons++;
                    if (new_cost < best_cost) {
                        best_warehouse = i;
                        best_cost = new_cost;
                        found_improvement = true;
                    }
                }
            }
            num_comparisons++;

            num_comparisons++;
            if (found_improvement) {
                solution.assignment[j] = best_warehouse;
                tabu_list.insert(best_warehouse);
                num_comparisons++;
                if (tabu_list.size() > tabu_tenure) {
                    tabu_list.erase(tabu_list.begin());
                }
                iterations_without_improvement = 0;
            } else {
                 num_comparisons++;
                iterations_without_improvement++;
            }
        }

        num_comparisons++;
        if (!found_improvement) {
            iterations_without_improvement++;
        }

        double assign_cost = 0.0;
        for(int i = 0; i < problem.getNumberOfCustomers(); i++)
        {
            assign_cost += problem.getCustomers()[i].getAllocationCosts()[solution.assignment[i]];
        }
        logger.logGeneral(curr_iteration, num_comparisons, -1, -1, -1, solution.total_cost, assign_cost);
    }

    solution.total_cost = calculateCost(solution.assignment, problem);
}

/**
 * Generates a new solution by adaptively perturbing a portion of the current solution based on the iteration number.
 */
algorithm::SimulatedAnnealingAlgorithm::Solution algorithm::SimulatedAnnealingAlgorithm::adaptivePerturbation(const Solution& current_solution, const Problem& problem, int iteration) const {
    RandomGenerator random;
    Solution new_solution = current_solution;

    int num_customers = problem.getNumberOfCustomers();
    int perturbation_size = (iteration % 2 == 0) ? num_customers / 3 : num_customers / 5;

    std::unordered_set<int> perturbed_customers;
    while (perturbed_customers.size() < perturbation_size) {
        num_comparisons++;
        perturbed_customers.insert(random.getRandomInt(num_customers));
    }
    num_comparisons++;

    for (int client : perturbed_customers) {
        num_comparisons++;
        new_solution.assignment[client] = random.getRandomInt(problem.getNumberOfWarehouses());
    }
    num_comparisons++;

    return new_solution;
}

/**
 * Solves the problem using the simulated annealing algorithm.
 */
std::vector<std::pair<int, int>> algorithm::SimulatedAnnealingAlgorithm::solve(const Problem& problem) const {
    RandomGenerator random;
    int num_warehouses = problem.getNumberOfWarehouses();
    int num_customers = problem.getNumberOfCustomers();

    Solution initial_solution;
    initial_solution.assignment.resize(num_customers);
    for (int j = 0; j < num_customers; ++j) {
        num_comparisons++;
        initial_solution.assignment[j] = random.getRandomInt(num_warehouses);
    }
    num_comparisons++;

    initial_solution.total_cost = calculateCost(initial_solution.assignment, problem);

    Solution current_solution = initial_solution;
    Solution best_solution = current_solution;

    double temperature = initial_temperature;
    int iteration = 0;

    while (temperature > final_temperature) {
        curr_iteration++;
        num_comparisons++;
        for (int i = 0; i < iterations_per_temp; ++i) {
            num_comparisons++;
            Solution new_solution = generateNeighbor(current_solution, problem);
            new_solution.total_cost = calculateCost(new_solution.assignment, problem);
            localSearch(new_solution, problem, 6);

            double delta_cost = new_solution.total_cost - current_solution.total_cost;

            curr_delta = delta_cost;
            num_comparisons++;
            if (delta_cost < 0 || std::exp(-delta_cost / temperature) > random.getRandom()) {
                num_comparisons++;
                current_solution = new_solution;
            }

            num_comparisons++;
            if (current_solution.total_cost < best_solution.total_cost) {
                best_solution = current_solution;
                std::cout << "New Best solution found: " << best_solution.total_cost << std::endl;
            }

            logger.logSimulatedAnnealing(curr_iteration, curr_temp, current_solution.total_cost, new_solution.total_cost, curr_delta);
        }

        temperature *= cooling_rate;
        curr_temp = temperature;
        num_comparisons++;
        if (++iteration % 30 == 0) {
            current_solution = adaptivePerturbation(best_solution, problem, iteration);
            current_solution.total_cost = calculateCost(current_solution.assignment, problem);
        }

    }

    std::vector<std::pair<int, int>> result(num_customers);
    for (int j = 0; j < num_customers; ++j) {
        result[j] = std::make_pair(j, best_solution.assignment[j]);
    }

    logger.saveGeneralLogToFile();
    logger.saveSimulatedAnnealingLogToFile();

    return result;
}