#pragma once
#include <vector>
/**
* @brief Class representing a customer in a UFLP.
*/
class Customer {
private:
	int demand;
	std::vector<int> allocation_costs;

public:
	Customer(int dem, const std::vector<int>& costs) : demand(dem), allocation_costs(costs) {}

	int getDemand() const {
		return demand;
	}

	const std::vector<int>& getAllocationCosts() const {
		return allocation_costs;
	}
};