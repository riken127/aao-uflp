#pragma once
#include "Algorithm.hpp"
#include <vector>
#include <utility>

namespace algorithm {

    class ParticleSwarmOptimizationAlgorithm : public Algorithm {
    public:
        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
        ParticleSwarmOptimizationAlgorithm (const int swarm_size,const int max_iterations,const double inertia_weight, const double cognitive_coefficoent, const double social_coefficient)
            : swarmSize(swarm_size), maxIterations(max_iterations), inertiaWeight(inertia_weight), cognitiveCoefficient(cognitive_coefficoent), socialCoefficient(social_coefficient) {}
    private:
        double calculateCost(const Problem& problem, const std::vector<bool>& openWarehouses) const;
        void getInitialSolution(const Problem& problem, std::vector<bool>& openWarehouses) const;
        void getBestNeighbor(const Problem& problem, const std::vector<bool>& currentSolution, std::vector<bool>& bestNeighbor) const;
        void localSearch(const Problem& problem, std::vector<bool>& solution) const;

        const int swarmSize;
        const int maxIterations;
        const double inertiaWeight;
        const double cognitiveCoefficient;
        const double socialCoefficient;
    };

}