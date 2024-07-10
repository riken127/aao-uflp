#ifndef ALGORITHMLOGGER_H
#define ALGORITHMLOGGER_H

#include <vector>
#include <fstream>
#include <string>

namespace miscellaneous
{
    class AlgorithmLogger
    {
    public:
        struct GeneralLogEntry
        {
            std::string algorithm;
            unsigned long long iteration;
            unsigned long long num_comparisons;
            int facility_id;
            int customer_id;
            int open_facility;
            double cost;
            double assignment_cost;
        };

        struct CrowSearchLogEntry
        {
            unsigned long long iteration;
            int crow_index;
            double obj_value;
            std::vector<bool> position;
            bool awareness;
        };

        struct GRASPLogEntry
        {
            unsigned long long iteration;
            double current_obj;
            double best_cost;
            std::vector<bool> warehouse_open;
            std::vector<int> best_assignment;
            double total_cost;
            std::vector<double> customer_costs;
        };

        struct HillClimbingLogEntry
        {
            unsigned long long iteration;
            unsigned long long comparisons;
            double current_cost;
            std::vector<bool> open_warehouses;
            double elapsed_time;
        };

        struct SimulatedAnnealingLogEntry
        {
            unsigned long long iteration;
            double temperature;
            double current_cost;
            double new_cost;
            double delta_cost;
        };

        AlgorithmLogger(const std::string& filename, const std::string& algorithm_name,
                        const std::string& problem_name);
        ~AlgorithmLogger();

        void logGeneral(unsigned long long iteration, unsigned long long num_comparisons,
                        int facility_id, int customer_id, int open_facility, double cost, double assignment_cost);
        void logCrowSearch(unsigned long long iteration, int crow_index, double obj_value, const std::vector<bool>& position,
                           bool awareness);
        void logGRASP(unsigned long long iteration, double current_obj, double best_cost, const std::vector<bool>& warehouse_open,
                      const std::vector<int>& best_assignment, double total_cost,
                      const std::vector<double>& customer_costs);
        void logHillClimbing(unsigned long long iteration, unsigned long long comparisons, double current_cost, const std::vector<bool>& open_warehouses,
                             double elapsed_time);
        void logSimulatedAnnealing(unsigned long long iteration, double temperature, double current_cost, double new_cost, double delta_cost);

        void saveGeneralLogToFile();
        void saveCrowSearchLogToFile();
        void saveGRASPLogToFile();
        void saveHillClimbingLogToFile();
        void saveSimulatedAnnealingLogToFile();

    private:
        std::vector<GeneralLogEntry> general_logs;
        std::vector<CrowSearchLogEntry> crow_search_log_entries;
        std::vector<HillClimbingLogEntry> hill_climbing_log_entries;
        std::vector<SimulatedAnnealingLogEntry> simulated_annealing_log_entries;
        std::vector<GRASPLogEntry> grasp_log_entries;
        std::ofstream log_file;
        std::string algorithm;
        std::string problem;
    };
} // namespace miscellaneous

#endif // ALGORITHMLOGGER_H
