#include "Aco.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cfloat>

std::vector<std::pair<int, int>> algorithm::ACO::solve(const Problem& problem) const {
    int num_customers = problem.getNumberOfCustomers();
    int num_warehouses = problem.getNumberOfWarehouses();

    std::vector<std::vector<double>> pheromones;
    initialize_pheromones(num_customers, num_warehouses, pheromones);

    std::vector<std::pair<int, int>> best_solution;
    double best_cost = DBL_MAX;

    for (int iteration = 0; iteration < num_population; ++iteration) {
        std::vector<std::pair<int, int>> current_solution = construct_solution(problem, pheromones);
        double current_cost = evaluate_solution(problem, current_solution);

        if (current_cost < best_cost) {
            best_cost = current_cost;
            best_solution = current_solution;
        }

        local_pheromone_update(current_solution, pheromones);
        update_pheromones(best_solution, best_cost, pheromones);
    }

    return best_solution;
}

void algorithm::ACO::initialize_pheromones(int num_customers, int num_warehouses, std::vector<std::vector<double>>& pheromones) const {
    pheromones.resize(num_customers, std::vector<double>(num_warehouses, 1.0));
}

void algorithm::ACO::update_pheromones(const std::vector<std::pair<int, int>>& best_solution, double best_cost, std::vector<std::vector<double>>& pheromones) const {
    for (auto& pheromone : pheromones) {
        for (double& ph : pheromone) {
            ph *= (1.0 - rho);
        }
    }

    for (const auto& [customer, warehouse] : best_solution) {
        pheromones[customer][warehouse] += rho * q / best_cost;
    }
}

std::vector<std::pair<int, int>> algorithm::ACO::construct_solution(const Problem& problem, const std::vector<std::vector<double>>& pheromones) const {
    int num_customers = problem.getNumberOfCustomers();
    int num_warehouses = problem.getNumberOfWarehouses();
    std::vector<std::pair<int, int>> solution;

    for (int customer = 0; customer < num_customers; ++customer) {
        double sum_probabilities = 0.0;
        std::vector<double> probabilities(num_warehouses);

        for (int warehouse = 0; warehouse < num_warehouses; ++warehouse) {
            probabilities[warehouse] = pow(pheromones[customer][warehouse], alpha) *
                                       pow(1.0 / problem.getCustomers()[customer].getAllocationCosts()[warehouse], beta);
            sum_probabilities += probabilities[warehouse];
        }

        double rand_value = (double) rand() / RAND_MAX;
        double cumulative_probability = 0.0;

        for (int warehouse = 0; warehouse < num_warehouses; ++warehouse) {
            cumulative_probability += probabilities[warehouse] / sum_probabilities;
            if (rand_value <= cumulative_probability) {
                solution.emplace_back(customer, warehouse);
                break;
            }
        }
    }

    return solution;
}

double algorithm::ACO::evaluate_solution(const Problem& problem, const std::vector<std::pair<int, int>>& solution) const {
    double total_cost = 0.0;

    for (const auto& [customer, warehouse] : solution) {
        total_cost += problem.getCustomers()[customer].getAllocationCosts()[warehouse];
    }

    return total_cost;
}

void algorithm::ACO::local_pheromone_update(const std::vector<std::pair<int, int>>& solution, std::vector<std::vector<double>>& pheromones) const {
    for (const auto& [customer, warehouse] : solution) {
        pheromones[customer][warehouse] *= (1.0 - rho);
        pheromones[customer][warehouse] += rho * 0.00001;
    }
}
