#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "Algorithm.hpp"

#include <cstdint>
#include <vector>

namespace algorithm {

class HillClimbingAlgorithm : public Algorithm {
public:
    std::vector<std::pair<int, int>> solve(const Problem& problem) const override;

private:
    using WarehouseMask = std::vector<std::uint8_t>;

    double calculateCost(const Problem& problem, const WarehouseMask& openWarehouses) const;
    void getInitialSolution(const Problem& problem, WarehouseMask& openWarehouses) const;
    double getBestNeighborCost(const Problem& problem,
                               const WarehouseMask& currentSolution,
                               double currentCost,
                               WarehouseMask& bestNeighbor) const;
};

} // namespace algorithm
