#ifndef ALGORITHMLOGGER_H
#define ALGORITHMLOGGER_H

#include <string>
#include <vector>

namespace miscellaneous {

    class AlgorithmLogger {
    public:
        // Structure responsible for holding general log data.
        struct GeneralLogEntry {
            std::string algorithm;
            int iteration;
            unsigned long long num_comparisons;
            int facility_id;
            int customer_id;
            int open_facility;
            double cost;
            double assignment_cost;
        };

        // Structure responsible for holding data related to the Crow Search Algorithm.
        struct CrowSearchLogEntry {
            int iteration;
            int crow_index;
            double obj_value;
            std::vector<bool> position;
            bool awareness;
        };

        void logGeneral(const std::string& algorithm, int iteration, unsigned long long num_comparisons,
                        int facility_id, int customer_id, int open_facility, double cost, double assignment_cost);
        void logCrowSearch(int iteration, int crow_index, double obj_value, const std::vector<bool>& position, bool awareness);
        void saveGeneralLogToFile(const std::string& filename, const std::string& problem_name);
        void saveCrowSearchLogToFile(const std::string& filename, const std::string& problem_name);

    private:
        std::vector<GeneralLogEntry> general_logs;
        std::vector<CrowSearchLogEntry> crow_search_log_entries;
    };

} // namespace miscellaneous

#endif // ALGORITHMLOGGER_H
