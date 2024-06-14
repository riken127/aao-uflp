#pragma once
#include "Algorithm.hpp"

/**
 * @brief Namespace for algorithm classes
 */
namespace algorithm {
	class GeneticAlgorithm : public algorithm::Algorithm {
	private:
		struct Assignment {
			int customer_idx;
			int warehouse_idx;
			int cost;
		};

		std::vector<Assignment> calculateInitialAssignments(const std::vector<Customer>& customers, const std::vector<Warehouse>& warehouses) const;
		void sortAssignmentsByCost(std::vector<Assignment>& assignments) const;
		std::vector<int> findBestWarehouses(const std::vector<Assignment>& assignments, const std::vector<Warehouse>& warehouses, int num_customers) const;
	public:
		std::vector<std::pair<int, int>> solve(const Problem& problem) const override;
	};
}
