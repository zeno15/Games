#include "Room.hpp"

namespace Survival {

	const unsigned int Room::OutsideId = 0;

	Room::Room(const sf::Vector2u& _origin, const sf::Vector2u& _size) {
		static unsigned int id = OutsideId + 1;
		m_Bounds = sf::Rect<unsigned int>(_origin, _size);
		m_Id = id++;
	}
	
	Room::~Room() {}

	unsigned int Room::getId(void) const {
		return m_Id;
	}
	sf::Rect<unsigned int> Room::getBounds(void) const {
		return m_Bounds;
	}
}