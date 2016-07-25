#pragma once

#include <SFML/System/Vector2.hpp>

namespace Common {

	class VectorMath {
	public:
		static sf::Vector2f normalise(const sf::Vector2f& _vec);
		static float distanceSquared(const sf::Vector2f& _start, const sf::Vector2f& _end);
		static float distance(const sf::Vector2f& _start, const sf::Vector2f& _end);
		static float lengthSquared(const sf::Vector2f& _vec);
		static float length(const sf::Vector2f& _vec);
	};

}