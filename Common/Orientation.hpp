#pragma once

#include <SFML/System/Vector2.hpp>

namespace Common {

	class Orientation {
	public:
		enum Direction {
			North,
			South,
			East,
			West
		};

		static sf::Vector2f directionToVector(Direction _direction);
	};

}