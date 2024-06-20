//
// Created by henri on 6/16/2024.
//

#ifndef SIMULATEDANNEALINGALGORITHM_H
#define SIMULATEDANNEALINGALGORITHM_H
#include <vector>
#include <random>
#include "../problem/Problem.hpp"
class Problem;
namespace algorithm {

        class SimulatedAnnealingAlgorithm {
        public:
            struct Solution {
                std::vector<int> assignment;
                double total_cost = 0.0;
            };

            SimulatedAnnealingAlgorithm(double initial_temperature, double final_temperature, double cooling_rate, int iterations_per_temp)
                : initial_temperature(initial_temperature), final_temperature(final_temperature), cooling_rate(cooling_rate), iterations_per_temp(iterations_per_temp) {}

            std::vector<std::pair<int, int>> solve(const Problem& problem) const;

        private:
            double calculateCost(const std::vector<int>& assignment, const Problem& problem) const;
            Solution generateNeighbor(const Solution& current_solution, const Problem& problem) const;
            void localSearch(Solution& solution, const Problem& problem, int tabu_tenure) const;
            Solution adaptivePerturbation(const Solution& current_solution, const Problem& problem, int iteration) const;

            double initial_temperature;
            double final_temperature;
            double cooling_rate;
            int iterations_per_temp;
        };

        class RandomGenerator {
        public:
            RandomGenerator() : rng(std::random_device{}()), dist(0.0, 1.0) {}

            double getRandom() {
                return dist(rng);
            }

            int getRandomInt(int max) {
                std::uniform_int_distribution<int> distInt(0, max - 1);
                return distInt(rng);
            }

        private:
            std::mt19937 rng;
            std::uniform_real_distribution<double> dist;
        };
    }



#endif //SIMULATEDANNEALINGALGORITHM_H
