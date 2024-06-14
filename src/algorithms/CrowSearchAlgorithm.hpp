#pragma once

#include "Algorithm.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <cmath>
#include <cstring>

namespace algorithm {

    class CrowSearchAlgorithm : public Algorithm {
    private:
        static double closed_interval_rand(double x0, double x1);

        double UFLP(int loc, int cus, const std::vector<std::vector<double>>& customer,
            const std::vector<double>& location, const std::vector<bool>& per) const;

    public:
        std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
    };

} // namespace algorithm

