#pragma once
#include "Algorithm.hpp"

/**
 * @brief Class representing a Subtype of UFLP Solving Algorithms, in this case, Genetic Algorithms. 
*/
namespace algorithm {
	class GeneticAlgorithm : public algorithm::Algorithm {
	public:
		void solve(const Problem& problem) const override;
	};
}