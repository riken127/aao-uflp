#pragma once
#include "Algorithm.hpp"
#include <vector>

namespace algorithm {

    class VariableNeighborhoodSearchAlgorithm : public Algorithm {
    public:
        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
        VariableNeighborhoodSearchAlgorithm(int max_iterations, int k_max)
            : maxIterations(max_iterations), kMax(k_max) {}
    private:
        int maxIterations;
        int kMax;
        double calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const;
        void getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const;
        void shake(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& shakenSolution, int k) const;
        void localSearch(const Problem& problem, std::vector<bool>& solution) const;
    };

} // namespace algorithm
