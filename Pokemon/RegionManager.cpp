#include "RegionManager.hpp"

#include "Region.hpp"

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

}