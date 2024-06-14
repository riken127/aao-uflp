#pragma once
/**
 * @brief Class representing the Warehouses in a UFLP.
 */
class Warehouse {
private:
    int capacity;
    double fixed_cost;

public:
    Warehouse(int cap, double cost) : capacity(cap), fixed_cost(cost) {}

    int getCapacity() const {
        return capacity;
    }

    double getFixedCost() const {
        return fixed_cost;
    }
};