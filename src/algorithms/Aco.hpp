#pragma once
#include "Algorithm.hpp"
#include "../problem/Problem.hpp"
#include <vector>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace algorithm
{
	class ACO
	{
	public:
		ACO(int num_population, double alpha, double beta, double rho, double q)
			: num_population(num_population), alpha(alpha), beta(beta), rho(rho), q(q)
		{
			srand(time(0));
		}
		std::vector<std::pair<int, int>> solve(const Problem &problem) const;

	private:
		int num_population;
		double alpha;
		double beta;
		double rho;
		double q;

		void initialize_pheromones(int num_customers, int num_warehouses, std::vector<std::vector<double>> &pheromones) const;
		void update_pheromones(const std::vector<std::pair<int, int>> &best_solution, double best_cost, std::vector<std::vector<double>> &pheromones) const;
		std::vector<std::pair<int, int>> construct_solution(const Problem &problem, const std::vector<std::vector<double>> &pheromones) const;
		double evaluate_solution(const Problem &problem, const std::vector<std::pair<int, int>> &solution) const;
		void local_pheromone_update(const std::vector<std::pair<int, int>> &solution, std::vector<std::vector<double>> &pheromones) const;
	};
}
