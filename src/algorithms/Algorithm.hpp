#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "../problem/Problem.hpp"

#include <utility>
#include <vector>

/**
 * @brief Namespace for the algorithm classes
 */
namespace algorithm {
/**
 * @brief Abstract class for the algorithms
 */
class Algorithm {
public:
    virtual std::vector<std::pair<int, int>> solve(const Problem& problem) const = 0;
    virtual ~Algorithm() = default;
};
} // namespace algorithm
