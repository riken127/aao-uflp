#pragma once
#include "../misc/AlgorithmLogger.h"
#include "Algorithm.hpp"
#include <utility>
#include <vector>

namespace algorithm {

    class CrowSearchAlgorithm : public Algorithm {
    private:
        static double closed_interval_rand(double x0, double x1);
        static double UFLP(int loc, int cus, const std::vector<std::vector<double>>& customer,
                           const std::vector<double>& location, const std::vector<bool>& per, unsigned long long& num_comparisons);

        int population_size;
        double awareness_probability;
        int function_evaluations;
        miscellaneous::AlgorithmLogger& logger;

    public:
        CrowSearchAlgorithm(int pop_size, double ap, int func_evals, miscellaneous::AlgorithmLogger& algorithmLogger)
            : population_size(pop_size), awareness_probability(ap), function_evaluations(func_evals), logger(algorithmLogger) {}

        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
    };

} // namespace algorithm