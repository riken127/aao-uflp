#pragma once
#include "Problem.h"

/**
 * @brief Namespace for the algorithm classes 
 */
namespace algorithm {
	/**
	 * @brief Abstract class for the algorithms
	 */
	class Algorithm {
	public:
		virtual void solve(const Problem& problem) const = 0;
		virtual ~Algorithm() {}
	};
}