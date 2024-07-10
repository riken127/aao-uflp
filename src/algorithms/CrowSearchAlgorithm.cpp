#include "../misc/AlgorithmLogger.h"
#include "CrowSearchAlgorithm.hpp"
#include <cfloat>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

namespace algorithm {

std::default_random_engine generator(static_cast<unsigned>(std::time(nullptr)));

double CrowSearchAlgorithm::closed_interval_rand(double x0, double x1) {
    std::uniform_real_distribution<double> distribution(x0, x1);
    return distribution(generator);
}

double CrowSearchAlgorithm::UFLP(int loc, int cus, const std::vector<std::vector<double>>& customer,
                                 const std::vector<double>& location, const std::vector<bool>& per,
                                 unsigned long long& num_comparisons) {
    double cost = 0;
    double min_cost = 0;

    for (int i = 0; i < loc; ++i) {
        num_comparisons++;
        if (per[i]) {
            cost += location[i];
            num_comparisons++;
        }
    }
    num_comparisons++;

    for (int i = 0; i < cus; ++i) {
        num_comparisons++;
        min_cost = DBL_MAX;
        for (int j = 0; j < loc; ++j) {
            num_comparisons++;
            if (per[j] && customer[i][j] < min_cost) {
                min_cost = customer[i][j];
                num_comparisons++;
            }
        }
        num_comparisons++;
        cost += min_cost;
    }
    num_comparisons++;

    return cost;
}

std::vector<std::pair<int, int>> CrowSearchAlgorithm::solve(const Problem& problem) const {
    int loc = problem.getNumberOfWarehouses();
    int cus = problem.getNumberOfCustomers();

    const auto& customers = problem.getCustomers();
    const auto& warehouses = problem.getWarehouses();

    std::vector<double> location(loc);
    std::vector<std::vector<double>> customer(cus, std::vector<double>(loc));

    for (int i = 0; i < loc; ++i)
        location[i] = warehouses[i].getFixedCost();

    for (int i = 0; i < cus; ++i) {
        const std::vector<double>& costs = customers[i].getAllocationCosts();
        for (int j = 0; j < loc; ++j) {
            customer[i][j] = costs[j];
        }
    }

    const int N = population_size;  // Population size
    const double AP = awareness_probability;  // Awareness probability
    const int MAX_ITER = function_evaluations / N;  // Number of iterations
    unsigned long long comparisons = 0;
    std::vector<bool> x(loc);
    std::vector<int> follow(N);

    std::vector<double> obj_crows(N, 0);
    std::vector<double> obj_memory(N, 0);

    std::vector<std::vector<bool>> x_crows(N, std::vector<bool>(loc));
    std::vector<std::vector<bool>> x_memory(N, std::vector<bool>(loc));

    double global_best = DBL_MAX;

    std::vector<std::pair<int, int>> final_assignments;

    // Memory initialization with more strategic approach
    for (int i = 0; i < N; i++) {
        comparisons++;
        for (int j = 0; j < loc; j++) {
            comparisons++;
            comparisons++;
            if (closed_interval_rand(0, 1) < 0.5) {
                x_crows[i][j] = false;
                x_memory[i][j] = false;
                continue;
            }
            x_crows[i][j] = true;
            x_memory[i][j] = true;
        }
        comparisons++;
    }
    comparisons++;

    for (int i = 0; i < N; i++) {
        comparisons++;
        obj_memory[i] = UFLP(loc, cus, customer, location, x_crows[i], comparisons);
    }
    comparisons++;

    // Iterations start
    for (int iter = 0; iter < MAX_ITER; iter++) {
        comparisons++;
        for (int i = 0; i < N; i++) {
            comparisons++;
            obj_crows[i] = UFLP(loc, cus, customer, location, x_crows[i], comparisons);

            comparisons++;
            if (obj_crows[i] < obj_memory[i]) {
                obj_memory[i] = obj_crows[i];

                for (int j = 0; j < loc; j++) {
                    comparisons++;
                    x_memory[i][j] = x_crows[i][j];
                }
                comparisons++;
            }

            comparisons++;
            if (obj_memory[i] < global_best) {
                global_best = obj_memory[i];
                final_assignments.clear();

                // Update final_assignments with the new best assignments
                for (int k = 0; k < cus; ++k) {
                    comparisons++;
                    int warehouse_index = -1;
                    double min_cost = DBL_MAX;
                    for (int j = 0; j < loc; ++j) {
                        comparisons++;
                        comparisons++;
                        if (x_memory[i][j] && customer[k][j] < min_cost) {
                            comparisons++;
                            min_cost = customer[k][j];
                            warehouse_index = j;
                            logger.logGeneral(iter, comparisons, j, k, x_memory[i][j], global_best,
                customer[k][j]);
                        }
                        comparisons++;
                    }
                    comparisons++;
                    final_assignments.emplace_back(k, warehouse_index);
                    logger.logCrowSearch(iter, i, obj_crows[i], x_crows[i], closed_interval_rand(0, 1) > AP);
                }


            }


        }

        for (int i = 0; i < N; ++i) {
            comparisons++;
            follow[i] = std::ceil(N * closed_interval_rand(0, 1)) - 1;
        }
        comparisons++;


        for (int i = 0; i < N; ++i) {
        comparisons++;
        comparisons++;
            if (closed_interval_rand(0, 1) > AP) {
                for (int j = 0; j < loc; ++j) {
                comparisons++;
                    x_crows[i][j] = x_memory[i][j] ^ ((std::rand() & 1) & (x_memory[follow[i]][j] ^ x_memory[i][j]));
                }
                comparisons++;
            }
            else {
                for (int j = 0; j < loc; ++j) {
                    comparisons++;
                    x_crows[i][j] = closed_interval_rand(0, 1) < 0.5;
                }
                comparisons++;
            }
        }
    }

    // Log the results
    logger.saveGeneralLogToFile();
    logger.saveCrowSearchLogToFile();

    return final_assignments;
}

} // namespace algorithm