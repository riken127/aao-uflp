#pragma once
#include "../problem/Problem.hpp"
#include <vector>
#include <string> 

/**
 * @brief Namespace for utility classes
 */
namespace utilities {
    /**
     * @brief Abstract class for parsers
     */
    class Parser {
    public:
        virtual std::vector<std::pair<int, int>> parse(const std::string& filePath) const = 0;
        virtual ~Parser() {}
    };
}
