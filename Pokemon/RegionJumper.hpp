#pragma once

#include "Tile.hpp"
#include "RegionEntity.hpp"

namespace Pokemon {

	class RegionJumper : public Tile {
	public:
		RegionJumper(unsigned int _x, unsigned int _y, unsigned int _spritesheetX, unsigned int _spritesheetY, const std::string& _targetRegionName, unsigned int _targetRegionX, unsigned int _targetRegionY);
		~RegionJumper();

		virtual void onEntityEntered(RegionEntity *_entity);
		virtual void onEntityLeave(RegionEntity *_entity);
		virtual void onEntityMovedWithin(RegionEntity *_entity);

		std::string m_TargetRegionName;
		unsigned int m_TargetRegionX;
		unsigned int m_TargetRegionY;
	};

}