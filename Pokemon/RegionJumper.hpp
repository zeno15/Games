#pragma once

#include "Tile.hpp"

namespace Pokemon {

	class RegionJumper : public Tile {
	public:
		RegionJumper(unsigned int _x, unsigned int _y);
		~RegionJumper();
		
		virtual void onEntityEntered(Entity *_entity);
		virtual void onEntityLeave(Entity *_entity);
		virtual void onEntityMovedWithin(Entity *_entity);
	};

}