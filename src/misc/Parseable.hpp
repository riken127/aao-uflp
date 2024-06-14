#pragma once
#include <string>
#include "../problem/Problem.hpp"
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
	};
}
