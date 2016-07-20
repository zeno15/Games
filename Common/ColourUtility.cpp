#include "ColourUtility.hpp"

#include <cstdlib>

namespace Common {

	sf::Color ColourUtility::randomColour(void) {

		auto r = rand() % 255;
		auto g = rand() % 255;
		auto b = rand() % 255;

		return sf::Color(r, g, b);
	}
}
