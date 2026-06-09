#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "../problem/Problem.hpp"

#include <string>

/**
 * @brief Namespace for the Miscellaneous classes
 */
namespace miscellaneous {
/**
 * @brief Abstract class for the parsers
 */
class Parseable {
public:
    virtual Problem parse(const std::string& path) const = 0;
    virtual ~Parseable() = default;
};
} // namespace miscellaneous
