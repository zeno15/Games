#include "Orientation.hpp"


namespace Common {

	sf::Vector2f Orientation::directionToVector(Direction _direction) {
		switch (_direction) {
		case Direction::North:
			return sf::Vector2f(0.0f, -1.0f);
		case Direction::East:
			return sf::Vector2f(+1.0f, 0.0f);
		case Direction::South:
			return sf::Vector2f(0.0f, +1.0f);
		case Direction::West:
			return sf::Vector2f(-1.0f, 0.0f);
		default:
			return sf::Vector2f();
		}
	}

}