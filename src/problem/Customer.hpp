#pragma once
#include <vector>

/**
 * @brief Class representing a customer in a UFLP.
 */
class Customer {
private:
    int demand;
    std::vector<double> allocation_costs;

public:
    Customer(int dem, const std::vector<double>& costs) : demand(dem), allocation_costs(costs) {}

    int getDemand() const {
        return demand;
    }

    const std::vector<double>& getAllocationCosts() const {
        return allocation_costs;
    }
};
