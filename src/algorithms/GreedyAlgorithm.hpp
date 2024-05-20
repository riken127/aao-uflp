#pragma once
#include "Algorithm.hpp"
/**
 * @brief Class representing a Subtype of UFLP Solving Algorithms, in this case, Greedy Algorithms. 
*/
namespace algorithm {
	class GreedyAlgorithm : public algorithm::Algorithm {
	public: 
		std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
	};
}