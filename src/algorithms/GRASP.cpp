#include "GRASP.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <vector>

namespace algorithm
{
    /**
     * @brief Constructor for the GRASP class.
     *
     * @param num_iterations Number of iterations for the GRASP algorithm.
     * @param num_iterations_local Number of iterations for the local search heuristic.
     * @param alpha Parameter for the greedy randomized constructive phase.
     */
    GRASP::GRASP(double alpha)
        : alpha(alpha) {}

    /**
     * @brief Initializes the GRASP algorithm with the given problem.
     *
     * @param problem The problem instance to solve.
     *
     * This function initializes various parameters and data structures required for the GRASP algorithm,
     * including the number of customers, the number of warehouses, fixed costs, allocation costs, and assignment vectors.
     */
    void GRASP::initialize(const Problem &problem){
        number_of_customers = problem.getNumberOfCustomers();
        number_of_warehouses = problem.getNumberOfWarehouses();

        fixed_costs.resize(number_of_warehouses);
        allocation_costs.resize(number_of_warehouses, std::vector<double>(number_of_customers));

        for (int i = 0; i < number_of_warehouses; ++i){
            fixed_costs[i] = problem.getWarehouses()[i].getFixedCost();
        }

        for (int j = 0; j < number_of_customers; ++j){
            for (int i = 0; i < number_of_warehouses; ++i){
                allocation_costs[i][j] = problem.getCustomers()[j].getAllocationCosts()[i];
            }
        }

        best_assignment.resize(number_of_customers);
        warehouse_open.resize(number_of_warehouses, false);
        customer_assignment.resize(number_of_customers);
    }

    /**
     * @brief Reassigns customers to the currently open warehouses to minimize costs.
     *
     * @return The total cost of the current assignment.
     *
     * This function calculates the minimum cost assignment of customers to open warehouses.
     * It updates the customer assignment and calculates the total cost considering both fixed and allocation costs.
     */
    double GRASP::ReassignCustomers(){
        std::vector<double> customer_min_cost(number_of_customers, MAX_DOUBLE);
        std::vector<int> best_assignment_temp(number_of_customers, -1);

        for (int j = 0; j < number_of_customers; ++j){
            double assign_cost = MAX_DOUBLE;
            int best_warehouse = -1;

            for (int i = 0; i < number_of_warehouses; ++i){
                if (warehouse_open[i] && allocation_costs[i][j] < assign_cost){
                    assign_cost = allocation_costs[i][j];
                    best_warehouse = i;
                }
            }
            customer_min_cost[j] = assign_cost;
            best_assignment_temp[j] = best_warehouse;
        }

        double cost = 0;

        for (int i = 0; i < number_of_warehouses; ++i){
            if (warehouse_open[i]){
                cost += fixed_costs[i];
            }
        }

        for (int j = 0; j < number_of_customers; ++j){
            if (best_assignment_temp[j] != -1){
                cost += customer_min_cost[j];
                customer_assignment[j] = best_assignment_temp[j];
            }
        }

        return cost;
    }

    /**
     * @brief Attempts to close one of the currently open warehouses to reduce costs.
     *
     * @return True if a warehouse was successfully closed to reduce costs, false otherwise.
     *
     * This function iterates over all open warehouses and attempts to close each one,
     * reassigning customers to minimize costs. If closing a warehouse reduces the total cost,
     * the function keeps it closed.
     */
    bool GRASP::CloseWarehouse(){
        int best_warehouse = -1;

        for (int i = 0; i < number_of_warehouses; ++i){
            if (warehouse_open[i]){
                warehouse_open[i] = false;
                double cost = ReassignCustomers();

                if (cost < current_objective){
                    current_objective = cost;
                    best_warehouse = i;
                }

                warehouse_open[i] = true;
            }
        }

        if (best_warehouse != -1){
            warehouse_open[best_warehouse] = false;
            return true;
        }

        return false;
    }

    /**
     * @brief Attempts to open one of the currently closed warehouses to reduce costs.
     *
     * @return True if a warehouse was successfully opened to reduce costs, false otherwise.
     *
     * This function iterates over all closed warehouses and attempts to open each one,
     * reassigning customers to minimize costs. If opening a warehouse reduces the total cost,
     * the function keeps it open.
     */
    bool GRASP::OpenWarehouse(){
        int best_warehouse = -1;

        for (int i = 0; i < number_of_warehouses; ++i){
            if (!warehouse_open[i]){
                warehouse_open[i] = true;
                double cost = ReassignCustomers();

                if (cost < current_objective){
                    current_objective = cost;
                    best_warehouse = i;
                }

                warehouse_open[i] = false;
            }
        }

        if (best_warehouse != -1){
            warehouse_open[best_warehouse] = true;
            return true;
        }

        return false;
    }

    /**
     * @brief Attempts to simultaneously open one closed warehouse and close one open warehouse to reduce costs.
     *
     * @return True if a pair of warehouses was successfully opened and closed to reduce costs, false otherwise.
     *
     * This function iterates over all pairs of open and closed warehouses, attempting to open a closed warehouse
     * and close an open warehouse simultaneously. If this operation reduces the total cost, the function keeps the
     * changes.
     */
    bool GRASP::OpenCloseWarehouse(){
        int best_open = -1;
        int best_closed = -1;

        for (int i1 = 0; i1 < number_of_warehouses; ++i1){
            if (!warehouse_open[i1]){
                for (int i2 = 0; i2 < number_of_warehouses; ++i2){
                    if (warehouse_open[i2]){
                        warehouse_open[i1] = true;
                        warehouse_open[i2] = false;
                        double cost = ReassignCustomers();

                        if (cost < current_objective){
                            current_objective = cost;
                            best_open = i1;
                            best_closed = i2;
                        }

                        warehouse_open[i1] = false;
                        warehouse_open[i2] = true;
                    }
                }
            }
        }

        if (best_open != -1 && best_closed != -1){
            warehouse_open[best_open] = true;
            warehouse_open[best_closed] = false;
            return true;
        }

        return false;
    }

    /**
     * @brief Performs a local search heuristic to optimize the current solution.
     *
     * @param objective The current objective cost.
     * @return The optimized objective cost after local search.
     *
     * This function applies a local search heuristic, iteratively attempting to open, close, and
     * open-close warehouses to reduce the objective cost. The search stops if no improvement is found
     * or the maximum number of local iterations is reached.
     */
    double GRASP::LocalSearchHeuristic(double objective){
        current_objective = objective;
        bool improved = true;
        int iterations = 0;

        while (improved){
            improved = false;

            if (CloseWarehouse()){
                improved = true;
                current_objective = ReassignCustomers();
            }

            if (!improved && OpenWarehouse()){
                improved = true;
                current_objective = ReassignCustomers();
            }

            if (!improved && OpenCloseWarehouse()){
                improved = true;
                current_objective = ReassignCustomers();
            }

            iterations++;
        }

        current_objective = ReassignCustomers();

        return current_objective;
    }

    /**
     * @brief Constructs a greedy randomized solution and applies local search to it.
     *
     * @return The cost of the constructed solution.
     *
     * This function performs the greedy randomized constructive phase of the GRASP algorithm.
     * It iteratively opens warehouses based on a restricted candidate list determined by the parameter alpha,
     * then applies local search to optimize the solution.
     */
    double GRASP::GreedyRandomizedConstructive(){
        double best_cost = MAX_DOUBLE;

        std::fill(warehouse_open.begin(), warehouse_open.end(), false);
        std::fill(best_assignment.begin(), best_assignment.end(), -1);

        while (true){
            int best_warehouse = -1;
            double imp_cost = best_cost;
            std::vector<int> restricted_candidate_list;
            double min_cost = MAX_DOUBLE;
            double max_cost = -MAX_DOUBLE;
            std::vector<double> costs(number_of_warehouses, MAX_DOUBLE);
            std::vector<bool> is_open(number_of_warehouses, false);
            std::vector<std::thread> threads;

            for (int i = 0; i < number_of_warehouses; ++i){
                if (!warehouse_open[i]){
                    threads.push_back(std::thread([&, i]{
                        warehouse_open[i] = true;
                        double cost = ReassignCustomers();
                        warehouse_open[i] = false;
                        costs[i] = cost;
                        is_open[i] = true;
                        }));
                }
            }

            for (auto &th : threads){
                if (th.joinable()){
                    th.join();
                }
            }

            for (int i = 0; i < number_of_warehouses; ++i){
                if (is_open[i]){
                    if (costs[i] < min_cost)
                        min_cost = costs[i];
                    if (costs[i] > max_cost)
                        max_cost = costs[i];
                }
            }

            double threshold = min_cost + alpha * (max_cost - min_cost);

            for (int i = 0; i < number_of_warehouses; ++i){
                if (is_open[i] && costs[i] <= threshold){
                    restricted_candidate_list.push_back(i);
                }
            }

            if (restricted_candidate_list.empty())
                break;

            int chosen_index = rand() % restricted_candidate_list.size();
            best_warehouse = restricted_candidate_list[chosen_index];
            warehouse_open[best_warehouse] = true;
            best_cost = ReassignCustomers();

            for (int j = 0; j < number_of_customers; ++j){
                best_assignment[j] = customer_assignment[j];
            }
        }

        return best_cost;
    }

    /**
     * @brief Solves the given problem using the GRASP algorithm.
     *
     * @param problem The problem instance to solve.
     * @return A vector of pairs representing the assignment of customers to warehouses.
     *
     * This function performs the GRASP algorithm over multiple iterations, each time constructing
     * a greedy randomized solution and applying local search to optimize it. The best solution found
     * across all iterations is returned as a vector of customer-to-warehouse assignments.
     */
    std::vector<std::pair<int, int>> GRASP::solve(const Problem &problem){
        initialize(problem);

        double best_cost = MAX_DOUBLE;
        double cost = GreedyRandomizedConstructive();
        cost = LocalSearchHeuristic(cost);

        if (cost < best_cost){
            best_cost = cost;

            for (int j = 0; j < number_of_customers; ++j){
                best_assignment[j] = customer_assignment[j];
            }
        }

        warehouse_open = best_warehouse_open;

        for (int j = 0; j < number_of_customers; ++j){
            customer_assignment[j] = best_assignment[j];
        }

        std::vector<std::pair<int, int>> result;

        for (int i = 0; i < number_of_customers; ++i){
            result.push_back({i, best_assignment[i]});
        }

        return result;
    }
}