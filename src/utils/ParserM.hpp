#pragma once
#include "../problem/Problem.hpp"
#include <vector>
#include <string> 

namespace utilities {
    /**
     * @brief ParserM class for parsing files
     */
    class ParserM : public Parser {
        private:
        struct 
    public:
        /**
         * @brief Parses the file and returns a vector of pairs of integers
         * @param filePath The path to the file to parse
         * @return A vector of pairs of integers parsed from the file
         */
        std::vector<std::pair<int, int>> parse(const std::string& filePath) const override;
    };
}
