#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "../problem/Problem.hpp"

#include <cstdint>
#include <limits>
#include <random>
#include <utility>
#include <vector>

namespace algorithm {

class GRASP {
private:
    using WarehouseMask = std::vector<std::uint8_t>;

    static constexpr double MAX_DOUBLE = std::numeric_limits<double>::max();

    std::vector<std::vector<double>> allocation_costs;
    std::vector<double> fixed_costs;
    double current_objective = MAX_DOUBLE;
    std::vector<int> best_assignment;
    int number_of_customers = 0;
    int number_of_warehouses = 0;
    WarehouseMask warehouse_open;
    std::vector<int> customer_assignment;
    WarehouseMask best_warehouse_open;
    double alpha;
    std::mt19937 rng;

    bool CloseWarehouse();
    bool OpenWarehouse();
    bool OpenCloseWarehouse();
    double LocalSearchHeuristic(double objective);
    double GreedyRandomizedConstructive();
    double ReassignCustomers();
    double Evaluate(const WarehouseMask& openWarehouses, std::vector<int>* assignment) const;

public:
    explicit GRASP(double alpha);
    void initialize(const Problem& problem);
    std::vector<std::pair<int, int>> solve(const Problem& problem);
};

} // namespace algorithm
