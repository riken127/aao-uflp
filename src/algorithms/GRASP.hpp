#pragma once
#include "../problem/Problem.hpp"
#include <vector>
#include <limits>

namespace algorithm {

    class GRASP {
    private:
        std::vector<std::vector<double>> allocation_costs;
        std::vector<double> fixed_costs;
        double current_objective;
        std::vector<int> best_assignment;
        int number_of_customers;
        const double MAX_DOUBLE = std::numeric_limits<double>::max();
        int number_of_warehouses;
        std::vector<bool> warehouse_open;
        std::vector<int> customer_assignment;
        std::vector<bool> best_warehouse_open;
        double alpha;

        bool CloseWarehouse();
        bool OpenWarehouse();
        bool OpenCloseWarehouse();
        double LocalSearchHeuristic(double objective);
        double GreedyRandomizedConstructive();
        double ReassignCustomers();

    public:
        GRASP(double alpha);
        void initialize(const Problem& problem);
        std::vector<std::pair<int, int>> solve(const Problem& problem);
    };
}