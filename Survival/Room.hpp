#pragma once

#include <SFML/Graphics.hpp>

namespace Survival {

	class Room {
	public:
		Room(const sf::Vector2u& _origin, const sf::Vector2u& _size);
		~Room();

		unsigned int getId(void) const;
		sf::Rect<unsigned int> getBounds(void) const;

		static const unsigned int OutsideId;

	private:
		unsigned int m_Id;
		sf::Rect<unsigned int> m_Bounds;
	};

}