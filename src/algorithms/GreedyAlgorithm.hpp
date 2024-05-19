#pragma once
#include "Algorithm.hpp"

/**
 * @brief Class representing a Subtype of UFLP Solving Algorithms, in this case, Greedy Algorithms. 
*/
class algorithm::GreedyAlgorithm : public Algorithm {
public: 
	void solve(const Problem& problem) const override;
};