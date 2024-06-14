#pragma once

#include "Algorithm.hpp"
#include "../problem/Problem.hpp"
#include <vector>
#include <unordered_set>
#include <utility>

namespace algorithm {

    class TabuSearchAlgorithm : public Algorithm {
    private:
        // Defina uma função de hash personalizada para `std::vector<std::pair<int, int>>`
        struct VectorPairHash {
            std::size_t operator()(const std::vector<std::pair<int, int>>& vec) const {
                std::size_t seed = vec.size();
                for (auto& i : vec) {
                    seed ^= std::hash<int>()(i.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                    seed ^= std::hash<int>()(i.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                }
                return seed;
            }
        };

    public:
        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;

        std::vector<std::pair<int, int>> generateInitialSolution(const Problem& problem) const;
        std::vector<std::vector<std::pair<int, int>>> generateNeighbors(const std::vector<std::pair<int, int>>& solution) const;

    private:
        double calculateCost(const std::vector<std::pair<int, int>>& solution, const Problem& problem) const;
    };
}
