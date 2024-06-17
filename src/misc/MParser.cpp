#include "MParser.hpp"
#include "../problem/Problem.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

Problem miscellaneous::MParser::parse(const std::string& path) const {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    Problem problem;
    std::string line;

    // Read number of warehouses and customers
    if (!std::getline(file, line)) {
        throw std::runtime_error("Error reading the number of warehouses and customers");
    }
    std::istringstream iss(line);
    if (!(iss >> problem.num_warehouses >> problem.num_customers)) {
        throw std::runtime_error("Error parsing the number of warehouses and customers");
    }

    // Read warehouses
    for (int i = 0; i < problem.num_warehouses; ++i) {
        int capacity;
        double fixed_cost;
        if (!std::getline(file, line)) {
            throw std::runtime_error("Error reading warehouse data");
        }
        std::istringstream iss(line);
        if (!(iss >> capacity >> fixed_cost)) {
            throw std::runtime_error("Error parsing warehouse data");
        }
        problem.warehouses.emplace_back(capacity, fixed_cost);
    }

    // Read customer data
    for (int i = 0; i < problem.num_customers; ++i) {
        int demand;
        if (!std::getline(file, line)) {
            throw std::runtime_error("Error reading customer demand");
        }
        std::istringstream iss(line);
        if (!(iss >> demand)) {
            throw std::runtime_error("Error parsing customer demand");
        }

        std::vector<double> allocation_costs;
        allocation_costs.reserve(problem.num_warehouses);

        int num_lines = (problem.num_warehouses + 7) / 8; // Determine the number of lines needed to read all costs
        for (int l = 0; l < num_lines; ++l) {
            if (!std::getline(file, line)) {
                throw std::runtime_error("Error reading allocation costs");
            }
            std::istringstream cost_stream(line);
            double cost;
            while (cost_stream >> cost) {
                allocation_costs.push_back(cost);
            }
        }

        if (allocation_costs.size() != problem.num_warehouses) {
            throw std::runtime_error("Mismatch in the number of allocation costs");
        }

        problem.customers.emplace_back(demand, allocation_costs);
    }

    return problem;
}