#pragma once
#include "Algorithm.hpp"
#include <vector>

namespace algorithm {

class HillClimbingAlgorithm : public Algorithm {
public:
    std::vector<std::pair<int, int>> solve(const Problem& problem) const override;

private:
    double calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const;
    void getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const;
    void getBestNeighbor(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& bestNeighbor) const;
};

} 
