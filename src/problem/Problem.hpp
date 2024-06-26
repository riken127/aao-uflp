
#pragma once
#include "Warehouse.hpp"
#include "Customer.hpp"

/**
 * @brief Represents a UFL Problem instance.
 * A problem instance consists of a number of customers and a number of warehouses.
 * It also contains a list of warehouses and a list of customers.
 */
class Problem {
public:
    Problem() : num_customers(0), num_warehouses(0) {} // Default constructor
    Problem(int num_cust, int num_wh) : num_customers(num_cust), num_warehouses(num_wh) {}

    void addWarehouse(const Warehouse& wh) {
        warehouses.push_back(wh);
    }

    void addCustomer(const Customer& cust) {
        customers.push_back(cust);
    }

    int getNumberOfCustomers() const {
        return num_customers;
    }

    int getNumberOfWarehouses() const {
        return num_warehouses;
    }

    const std::vector<Warehouse>& getWarehouses() const {
        return warehouses;
    }

    const std::vector<Customer>& getCustomers() const {
        return customers;
    }
    int num_customers;
    int num_warehouses;
    std::vector<Warehouse> warehouses;
    std::vector<Customer> customers;

};