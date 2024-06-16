#include "AlgorithmLogger.h"
#include <fstream>
#include <iostream>

namespace miscellaneous {

void AlgorithmLogger::logGeneral(const std::string& algorithm, int iteration, unsigned long long num_comparisons,
                                 int facility_id, int customer_id, int open_facility, double cost, double assignment_cost) {
    std::cout << num_comparisons << std::endl;
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

void AlgorithmLogger::logCrowSearch(int iteration, int crow_index, double obj_value, const std::vector<bool>& position, bool awareness) {
    crow_search_log_entries.push_back({
        iteration,
        crow_index,
        obj_value,
        position,
        awareness
    });
}

void AlgorithmLogger::saveGeneralLogToFile(const std::string& filename, const std::string& problem_name) {
    std::ofstream general_file(filename);
    general_file << "Algorithm,Problem,Iteration,Num_Comparisons,Facility_ID,Customer_ID,Open_Facility,Cost,Assignment_Cost\n";
    for (const auto& log : general_logs) {
        general_file << log.algorithm << "," << problem_name << "," << log.iteration << "," << log.num_comparisons << ","
                     << log.facility_id << "," << log.customer_id << "," << log.open_facility << "," << log.cost << ","
                     << log.assignment_cost << "\n";
    }
    general_file.close();
}

void AlgorithmLogger::saveCrowSearchLogToFile(const std::string& filename, const std::string& problem_name) {
    std::ofstream crow_search_file(filename);
    crow_search_file << "Problem,Iteration,Crow_Index,Obj_Value,Position,Awareness\n";
    for (const auto& log : crow_search_log_entries) {
        crow_search_file << problem_name << "," << log.iteration << "," << log.crow_index << "," << log.obj_value << ",\"";
        for (bool pos : log.position) {
            crow_search_file << pos << " ";
        }
        crow_search_file << "\"," << log.awareness << "\n";
    }
    crow_search_file.close();
}

} // namespace miscellaneous
