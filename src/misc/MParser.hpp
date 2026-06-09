#pragma once

// Maintainer: riken127 <henriquenoronha05@gmail.com>

#include "Parseable.hpp"

/**
 * @brief Namespace for the miscellaneous classes
 */
namespace miscellaneous {
	class MParser : public Parseable {
	public:
		Problem parse(const std::string& path) const override;
	};
} // namespace miscellaneous
