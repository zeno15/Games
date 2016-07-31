#include "RegionManager.hpp"

#include "Region.hpp"
#include "RegionEntity.hpp"

#include <iostream>

namespace Pokemon {

	const std::string RegionManager::Name = "RegionManager";

	RegionManager::RegionManager() {}

	RegionManager::~RegionManager() {}


	Region *RegionManager::getCurrentRegion(void) {
		return m_CurrentRegion;
	}
	void RegionManager::setCurrentRegion(Region *_region) {
		m_CurrentRegion = _region;
	}
	void RegionManager::setCurrentRegion(const std::string& _regionName) {
		for (auto& r : m_Regions) {
			if (r->getName() == _regionName) {
				m_CurrentRegion = r;
				return;
			}
		}
	}
	void RegionManager::addRegion(Region *_region) {
		auto& n = _region->getName();
		for (auto& r : m_Regions) {
			if (r->getName() == n) {
				return;
			}
		}
		m_Regions.push_back(_region);
	}

	bool RegionManager::jumpRegion(const std::string& _targetRegion, unsigned int _x, unsigned int _y, RegionEntity *_entity, bool _updateCurrentRegion) {
		if (hasRegion(_targetRegion)) {
			std::cout << "Region '" << _targetRegion << "' is present" << std::endl;
			auto& r = getRegion(_targetRegion);

			r.addEntity(_entity);
			_entity->setPosition(sf::Vector2f(static_cast<float>(_x), static_cast<float>(_y)));
			if (_updateCurrentRegion) {
				setCurrentRegion(_targetRegion);
			}
			return true;
		}
		return false;
	}
	bool RegionManager::hasRegion(const std::string& _regionName) const {
		for (auto& r : m_Regions) {
			if (r->getName() == _regionName) {
				return true;
			}
		}

		return false;
	}
	Region& RegionManager::getRegion(const std::string& _regionName) {
		for (auto& r : m_Regions) {
			if (r->getName() == _regionName) {
				return *r;
			}
		}

		throw std::runtime_error("Region" + _regionName + " was not present");
	}
}