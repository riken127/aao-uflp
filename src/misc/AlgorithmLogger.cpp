#include "AlgorithmLogger.h"
#include <iostream>

namespace miscellaneous
{
    AlgorithmLogger::AlgorithmLogger(const std::string& filename, const std::string& algorithm_name,
                                     const std::string& problem_name)
    {
        log_file.open(filename, std::ios::out | std::ios::app);
        algorithm = algorithm_name;
        problem = problem_name;
        if (!log_file.is_open())
        {
            std::cerr << "Error opening log file: " << filename << std::endl;
        }
    }

    AlgorithmLogger::~AlgorithmLogger()
    {
        if (log_file.is_open())
        {
            log_file.close();
        }
    }

    void AlgorithmLogger::logGeneral(int iteration, unsigned long long num_comparisons,
                                     int facility_id, int customer_id, int open_facility, double cost,
                                     double assignment_cost)
    {
        general_logs.push_back({
            algorithm,
            iteration,
            num_comparisons,
            facility_id,
            customer_id,
            open_facility,
            cost,
            assignment_cost
        });
    }

    void AlgorithmLogger::logCrowSearch(int iteration, int crow_index, double obj_value,
                                        const std::vector<bool>& position, bool awareness)
    {
        crow_search_log_entries.push_back({
            iteration,
            crow_index,
            obj_value,
            position,
            awareness
        });
    }

    void AlgorithmLogger::logGRASP(int iteration, double current_obj, double best_cost,
                                   const std::vector<bool>& warehouse_open,
                                   const std::vector<int>& best_assignment, double total_cost,
                                   const std::vector<double>& customer_costs)
    {
        grasp_log_entries.push_back({
            iteration,
            current_obj,
            best_cost,
            warehouse_open,
            best_assignment,
            total_cost,
            customer_costs
        });
    }

    void AlgorithmLogger::logHillClimbing(int iteration, double current_cost, const std::vector<bool>& open_warehouses,
                                          double elapsed_time)
    {
        hill_climbing_log_entries.push_back({
            iteration,
            current_cost,
            open_warehouses,
            elapsed_time
        });
    }

    void AlgorithmLogger::logSimulatedAnnealing(int iteration, double temperature, double current_cost, double new_cost,
                                                double best_cost, double delta_cost)
    {
        simulated_annealing_log_entries.push_back({
            iteration,
            temperature,
            current_cost,
            new_cost,
            best_cost,
            delta_cost
        });
    }

    void AlgorithmLogger::saveGeneralLogToFile()
    {
        std::ofstream general_file(algorithm + "_general_" + problem + ".csv");
        general_file <<
            "Algorithm,Problem,Iteration,Num_Comparisons,Facility_ID,Customer_ID,Open_Facility,Cost,Assignment_Cost\n";
        for (const auto& log : general_logs)
        {
            general_file << log.algorithm << "," << problem << "," << log.iteration << "," << log.num_comparisons << ","
                << log.facility_id << "," << log.customer_id << "," << log.open_facility << "," << log.cost << ","
                << log.assignment_cost << "\n";
        }
        general_file.close();
    }

    void AlgorithmLogger::saveCrowSearchLogToFile()
    {
        std::ofstream crow_search_file("crow_search_" + problem + ".csv");
        crow_search_file << "Problem,Iteration,Crow_Index,Obj_Value,Position,Awareness\n";
        for (const auto& log : crow_search_log_entries)
        {
            crow_search_file << problem << "," << log.iteration << "," << log.crow_index << "," << log.obj_value <<
                ",\"";
            for (bool pos : log.position)
            {
                crow_search_file << pos << " ";
            }
            crow_search_file << "\"," << log.awareness << "\n";
        }
        crow_search_file.close();
    }

    void AlgorithmLogger::saveGRASPLogToFile()
    {
        std::ofstream grasp_file("grasp_" + problem + ".csv");
        grasp_file <<
            "Problem,Iteration,Current_Objective,Best_Cost,Warehouse_Open,Best_Assignment,Total_Cost,Customer_Costs\n";
        for (const auto& log : grasp_log_entries)
        {
            grasp_file << problem << "," << log.iteration << "," << log.current_obj << "," << log.best_cost << ",\"";
            for (bool open : log.warehouse_open)
            {
                grasp_file << open << " ";
            }
            grasp_file << "\",\"";
            for (int assignment : log.best_assignment)
            {
                grasp_file << assignment << " ";
            }
            grasp_file << "\"," << log.total_cost << ",\"";
            for (double cost : log.customer_costs)
            {
                grasp_file << cost << " ";
            }
            grasp_file << "\"\n";
        }
        grasp_file.close();
    }

    void AlgorithmLogger::saveHillClimbingLogToFile()
    {
        std::ofstream hill_climbing_file("hill_climbing_" + problem + ".csv");
        hill_climbing_file << "Problem,Iteration,Current_Cost,Open_Warehouses,Elapsed_Time\n";
        for (const auto& log : hill_climbing_log_entries)
        {
            hill_climbing_file << problem << "," << log.iteration << "," << log.current_cost << ",\"";
            for (bool open : log.open_warehouses)
            {
                hill_climbing_file << open << " ";
            }
            hill_climbing_file << "\"," << log.elapsed_time << "\n";
        }
        hill_climbing_file.close();
    }

    void AlgorithmLogger::saveSimulatedAnnealingLogToFile()
    {
        std::ofstream sa_file("simulated_annealing_" + problem + ".csv");
        sa_file << "Problem,Iteration,Temperature,Current_Cost,New_Cost,Best_Cost,Delta_Cost\n";
        for (const auto& entry : simulated_annealing_log_entries)
        {
            sa_file << problem << "," << entry.iteration << "," << entry.temperature << ","
                << entry.current_cost << "," << entry.new_cost << "," << entry.best_cost << "," << entry.delta_cost <<
                "\n";
        }
        sa_file.close();
    }
} // namespace miscellaneous
