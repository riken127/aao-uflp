#pragma once
#include "../problem/Problem.hpp"

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
		virtual ~Algorithm() {}
	};
}