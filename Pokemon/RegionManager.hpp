#pragma once

#include "../Common/Manager.hpp"

#include <vector>

namespace Common {
	class InstanceCollection;
}

namespace Pokemon {
	class Region;
	class RegionEntity;
	class RegionManager : public Common::Manager {
	public:

		friend class Common::InstanceCollection;

		const static std::string Name;

		Region *getCurrentRegion(void);
		void setCurrentRegion(Region *_region);
		void setCurrentRegion(const std::string& _regionName);
		void addRegion(Region *_region);
		Region& getRegion(const std::string& _regionName);

		bool jumpRegion(const std::string& _targetRegion, unsigned int _x, unsigned int _y, RegionEntity *_entity, bool _updateCurrentRegion);
		bool hasRegion(const std::string& _regionName) const;

	private:
		RegionManager();
		~RegionManager();

		Region *m_CurrentRegion;
		std::vector<Region *> m_Regions;
	};

}