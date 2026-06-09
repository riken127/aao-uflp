// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "ORLibParser.hpp"
#include "../problem/Problem.hpp"

#include <fstream>
#include <stdexcept>
#include <utility>
#include <vector>

Problem miscellaneous::ORLibParser::parse(const std::string& path) const {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    Problem problem;

    if (!(file >> problem.num_warehouses >> problem.num_customers)) {
        throw std::runtime_error("Error reading number of warehouses and customers");
    }

    problem.reserveStorage();

    for (int i = 0; i < problem.num_warehouses; ++i) {
        int capacity;
        double fixed_cost;
        if (!(file >> capacity >> fixed_cost)) {
            throw std::runtime_error("Error reading warehouse data");
        }
        problem.addWarehouse(Warehouse{capacity, fixed_cost});
    }

    for (int i = 0; i < problem.num_customers; ++i) {
        int demand;
        if (!(file >> demand)) {
            throw std::runtime_error("Error reading customer demand");
        }

        std::vector<double> allocation_costs(problem.num_warehouses);
        for (int j = 0; j < problem.num_warehouses; ++j) {
            if (!(file >> allocation_costs[j])) {
                throw std::runtime_error("Error reading allocation costs");
            }
        }

        problem.addCustomer(Customer{demand, std::move(allocation_costs)});
    }

    return problem;
}
