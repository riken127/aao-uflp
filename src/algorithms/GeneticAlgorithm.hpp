#pragma once
#include "Algorithm.hpp"
#include "Problem.hpp"

/**
 * @brief Class representing a Subtype of UFLP Solving Algorithms, in this case, Genetic Algorithms. 
*/
class algorithm::GeneticAlgorithm : public Algorithm {
public:
	void solve(const Problem& problem) const override;
};