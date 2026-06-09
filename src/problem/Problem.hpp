#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "Warehouse.hpp"
#include "Customer.hpp"

#include <utility>
#include <vector>

/**
 * @brief Represents a UFL Problem instance.
 * A problem instance consists of a number of customers and a number of warehouses.
 * It also contains a list of warehouses and a list of customers.
 */
class Problem {
public:
    Problem() = default;

    Problem(int num_cust, int num_wh) : num_customers(num_cust), num_warehouses(num_wh) {
        customers.reserve(static_cast<std::size_t>(num_customers));
        warehouses.reserve(static_cast<std::size_t>(num_warehouses));
    }

    void addWarehouse(const Warehouse& wh) {
        warehouses.push_back(wh);
    }

    void addWarehouse(Warehouse&& wh) {
        warehouses.push_back(std::move(wh));
    }

    void addCustomer(const Customer& cust) {
        customers.push_back(cust);
    }

    void addCustomer(Customer&& cust) {
        customers.push_back(std::move(cust));
    }

    void reserveStorage() {
        customers.reserve(static_cast<std::size_t>(num_customers));
        warehouses.reserve(static_cast<std::size_t>(num_warehouses));
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

    int num_customers = 0;
    int num_warehouses = 0;
    std::vector<Warehouse> warehouses;
    std::vector<Customer> customers;
};
