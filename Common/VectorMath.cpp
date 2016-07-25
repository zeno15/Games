#include "VectorMath.hpp"

#include <cmath>

namespace Common {

	sf::Vector2f VectorMath::normalise(const sf::Vector2f& _vec) {
		return _vec / length(_vec);
	}

	float VectorMath::distanceSquared(const sf::Vector2f& _start, const sf::Vector2f& _end) {
		return lengthSquared(_end - _start);
	}
	float VectorMath::distance(const sf::Vector2f& _start, const sf::Vector2f& _end) {
		return std::sqrtf(distanceSquared(_start, _end));
	}

	float VectorMath::lengthSquared(const sf::Vector2f& _vec) {
		return _vec.x * _vec.x + _vec.y * _vec.y;
	}
	float VectorMath::length(const sf::Vector2f& _vec) {
		return std::sqrtf(lengthSquared(_vec));
	}
}