#include "RegionJumper.hpp"

#include "Region.hpp"
#include "RegionManager.hpp"
#include "../Common/InstanceCollection.hpp"

#include <iostream>

namespace Pokemon {

	RegionJumper::RegionJumper(unsigned int _x, unsigned int _y, unsigned int _spritesheetX, unsigned int _spritesheetY, const std::string& _targetRegionName, unsigned int _targetRegionX, unsigned int _targetRegionY) :
	Tile(_x, _y, _spritesheetX, _spritesheetY, true),
		m_TargetRegionName(_targetRegionName),
		m_TargetRegionX(_targetRegionX),
		m_TargetRegionY(_targetRegionY) {
	}


	RegionJumper::~RegionJumper() {}


	void RegionJumper::onEntityEntered(RegionEntity *_entity) {
		std::cout << "RegionJumper entity entered" << std::endl;
		if (_entity->canJumpRegions()) {
			std::cout << "Jump to region " << m_TargetRegionName << " at x: " << m_TargetRegionX << ", y: " << m_TargetRegionY << std::endl;
			auto& regionManager = Common::InstanceCollection::getInstance<RegionManager>();
			auto currentRegion = regionManager.getCurrentRegion();

			if (regionManager.jumpRegion(m_TargetRegionName, m_TargetRegionX, m_TargetRegionY, _entity, true)) {
				std::cout << "Succeeded, remove entity from current region" << std::endl;
				currentRegion->removeEntity(_entity);
			}
			else {
				std::cout << "Failed, keep entity in current region" << std::endl;
			}
		}
	}
	void RegionJumper::onEntityLeave(RegionEntity *_entity) {
		std::cout << "RegionJumper onEntityLeave" << std::endl;
	}
	void RegionJumper::onEntityMovedWithin(RegionEntity *_entity) {
		std::cout << "RegionJumper onEntityMovedWithin" << std::endl;
	}

}