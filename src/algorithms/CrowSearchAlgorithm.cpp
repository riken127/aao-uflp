#include "CrowSearchAlgorithm.hpp"
#include <random>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cfloat>
#include <vector>
#include <numeric>
#include <iostream>

namespace algorithm {

    std::default_random_engine generator(static_cast<unsigned>(std::time(nullptr)));

    double CrowSearchAlgorithm::closed_interval_rand(double x0, double x1) {
        std::uniform_real_distribution<double> distribution(x0, x1);
        return distribution(generator);
    }

    double CrowSearchAlgorithm::UFLP(int loc, int cus, const std::vector<std::vector<double>>& customer,
        const std::vector<double>& location, const std::vector<bool>& per) const {
        double cost = 0;
        double min_cost = 0;
        for (int i = 0; i < loc; ++i)
            if (per[i])
                cost += location[i];

        for (int i = 0; i < cus; ++i) {
            min_cost = DBL_MAX;
            for (int j = 0; j < loc; ++j) {
                if (per[j] && customer[i][j] < min_cost)
                    min_cost = customer[i][j];
            }
            cost += min_cost;
        }

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

        const int N = 400;  // Population size
        const double AP = 0.1;  // Awareness probability
        const int MAX_ITER = 84000 / N;  // Number of iterations

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
            for (int j = 0; j < loc; j++) {
                if (closed_interval_rand(0, 1) < 0.5) {
                    x_crows[i][j] = false;
                    x_memory[i][j] = false;
                    continue;
                }
                x_crows[i][j] = true;
                x_memory[i][j] = true;
            }
        }

        for (int i = 0; i < N; i++) {
            obj_memory[i] = UFLP(loc, cus, customer, location, x_crows[i]);
        }

        // Iterations start
        for (int iter = 0; iter < MAX_ITER; iter++) {
            for (int i = 0; i < N; i++) {
                obj_crows[i] = UFLP(loc, cus, customer, location, x_crows[i]);

                if (obj_crows[i] < obj_memory[i]) {
                    obj_memory[i] = obj_crows[i];

                    for (int j = 0; j < loc; j++) {
                        x_memory[i][j] = x_crows[i][j];
                    }
                }

                if (obj_memory[i] < global_best) {
                    global_best = obj_memory[i];
                    final_assignments.clear();

                    // Update final_assignments with the new best assignments
                    for (int k = 0; k < cus; ++k) {
                        int warehouse_index = -1;
                        double min_cost = DBL_MAX;
                        for (int j = 0; j < loc; ++j) {
                            if (x_memory[i][j] && customer[k][j] < min_cost) {
                                min_cost = customer[k][j];
                                warehouse_index = j;
                            }
                        }
                        final_assignments.emplace_back(k, warehouse_index);
                    }
                }
            }

            for (int i = 0; i < N; ++i) {
                follow[i] = std::ceil(N * closed_interval_rand(0, 1)) - 1;
            }

            for (int i = 0; i < N; ++i) {
                if (closed_interval_rand(0, 1) > AP) {
                    for (int j = 0; j < loc; ++j) {
                        x_crows[i][j] = x_memory[i][j] ^ ((rand() & 1) & (x_memory[follow[i]][j] ^ x_memory[i][j]));
                    }
                }
                else {
                    for (int j = 0; j < loc; ++j) {
                        x_crows[i][j] = closed_interval_rand(0, 1) < 0.5;
                    }
                }
            }
        }

        return final_assignments;
    }

} // namespace algorithm
