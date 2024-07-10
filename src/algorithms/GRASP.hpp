#pragma once

#include "../problem/Problem.hpp"
#include "../misc/AlgorithmLogger.h" // Include AlgorithmLogger header
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
        unsigned long long comparisons = 0;
        unsigned long long iteration = 0;
        std::vector<bool> warehouse_open;
        std::vector<int> customer_assignment;
        std::vector<bool> best_warehouse_open;
        double alpha;
        double minimum_cost = MAX_DOUBLE;

        // AlgorithmLogger instance
        miscellaneous::AlgorithmLogger& logger;

        bool CloseWarehouse();
        bool OpenWarehouse();
        bool OpenCloseWarehouse();
        double LocalSearchHeuristic(double objective, const Problem& problem);
        double GreedyRandomizedConstructive();
        double ReassignCustomers();

    public:
        // Constructor with AlgorithmLogger initialization
        GRASP(double alpha, miscellaneous::AlgorithmLogger& logger);
        void initialize(const Problem& problem);
        std::vector<std::pair<int, int>> solve(const Problem& problem);
    };

}
