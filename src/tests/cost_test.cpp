#include <iostream>
#include <cassert>
#include "../problem/Problem.hpp"

void testCalculateCost() {
    // Define um problema com 2 clientes e 2 armazéns
    Problem problem(2, 2);

    // Adiciona armazéns
    problem.addWarehouse(Warehouse(10, 5));
    problem.addWarehouse(Warehouse(15, 4));

    // Adiciona clientes com seus custos de alocação para cada armazém
    problem.addCustomer(Customer(5, {1, 3}));
    problem.addCustomer(Customer(10, {2, 1}));

    // Cria uma solução fictícia onde cada cliente é atribuído a um armazém
    std::vector<std::pair<int, int>> solution = {{0, 0}, {1, 1}};

    // Calcula o custo esperado
    double expectedCost = 1 + 1; // Custos de alocação para os clientes
    double calculatedCost = 0.0;

    for (const auto& assignment : solution) {
        calculatedCost += problem.getCost(assignment.first, assignment.second);
    }

    // Verifica se o custo calculado é igual ao custo esperado
    assert(calculatedCost == expectedCost);

    std::cout << "Teste de cálculo de custo passou." << std::endl;
}

int main() {
    testCalculateCost();
    return 0;
}
