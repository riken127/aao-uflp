#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "../problem/Problem.hpp"

#include <random>
#include <utility>
#include <vector>

namespace algorithm {

class SimulatedAnnealingAlgorithm {
public:
    struct Solution {
        std::vector<int> assignment;
        double total_cost = 0.0;
    };

    SimulatedAnnealingAlgorithm(double initial_temperature,
                                double final_temperature,
                                double cooling_rate,
                                int iterations_per_temp)
        : initial_temperature(initial_temperature),
          final_temperature(final_temperature),
          cooling_rate(cooling_rate),
          iterations_per_temp(iterations_per_temp),
          rng(std::random_device{}()) {}

    std::vector<std::pair<int, int>> solve(const Problem& problem) const;

private:
    double calculateCost(const std::vector<int>& assignment, const Problem& problem) const;
    Solution generateNeighbor(const Solution& current_solution, const Problem& problem) const;
    void localSearch(Solution& solution, const Problem& problem, int tabu_tenure) const;
    Solution adaptivePerturbation(const Solution& current_solution, const Problem& problem, int iteration) const;
    double randomUnit() const;
    int randomInt(int maxExclusive) const;

    double initial_temperature;
    double final_temperature;
    double cooling_rate;
    int iterations_per_temp;
    mutable std::mt19937 rng;
};

} // namespace algorithm
