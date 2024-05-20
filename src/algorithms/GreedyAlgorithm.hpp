#pragma once
#include "Algorithm.hpp"
/**
 * @brief Class representing a Subtype of UFLP Solving Algorithms, in this case, Greedy Algorithms. 
*/
namespace algorithm {
	class GreedyAlgorithm : public algorithm::Algorithm {
	public: 
		void solve(const Problem& problem) const override;
	};
}