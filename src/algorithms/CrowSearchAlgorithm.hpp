#pragma once

#include "Algorithm.hpp"
#include <vector>

namespace algorithm {

    class CrowSearchAlgorithm : public Algorithm {
    private:
        static double closed_interval_rand(double x0, double x1);
        static double UFLP(int loc, int cus, const std::vector<std::vector<double>>& customer,
                           const std::vector<double>& location, const std::vector<bool>& per);

        int population_size;
        double awareness_probability;
        int function_evaluations;

    public:
        CrowSearchAlgorithm(int pop_size, double ap, int func_evals)
            : population_size(pop_size), awareness_probability(ap), function_evaluations(func_evals) {}

        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
    };

} // namespace algorithm
