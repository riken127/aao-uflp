#pragma once
#include "Algorithm.hpp"
#include <vector>

#include "../misc/AlgorithmLogger.h"

namespace algorithm {

class HillClimbingAlgorithm : public Algorithm {
public:
    std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
    HillClimbingAlgorithm(miscellaneous::AlgorithmLogger& logger)
        : logger(logger) {}
private:
    double calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const;
    void getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const;
    void getBestNeighbor(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& bestNeighbor) const;
    miscellaneous::AlgorithmLogger& logger;
    mutable unsigned long long num_iterations = 0;
    mutable unsigned long long num_comparisons = 0;
    mutable double curr_total_assignment_cost = 0;
};

} 