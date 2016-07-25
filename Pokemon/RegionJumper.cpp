#include "RegionJumper.hpp"

#include <iostream>

namespace Pokemon {

	RegionJumper::RegionJumper(unsigned int _x, unsigned int _y) :
	Tile(_x, _y) {
		setFillColor(sf::Color::Yellow);
	}


	RegionJumper::~RegionJumper() {}


	void RegionJumper::onEntityEntered(Entity *_entity) {
		std::cout << "RegionJumper entity entered" << std::endl;
	}
	void RegionJumper::onEntityLeave(Entity *_entity) {
		std::cout << "RegionJumper onEntityLeave" << std::endl;
	}
	void RegionJumper::onEntityMovedWithin(Entity *_entity) {
		std::cout << "RegionJumper onEntityMovedWithin" << std::endl;
	}

}