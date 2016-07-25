#pragma once

#include "../Common/Manager.hpp"

#include <vector>

namespace Common {
	class InstanceCollection;
}

namespace Pokemon {
	class Region;
	class RegionManager : public Common::Manager {
	public:

		friend class Common::InstanceCollection;

		const static std::string Name;

		Region *getCurrentRegion(void);
		void setCurrentRegion(Region *_region);
		void setCurrentRegion(const std::string& _regionName);
		void addRegion(Region *_region);

	private:
		RegionManager();
		~RegionManager();

		Region *m_CurrentRegion;
		std::vector<Region *> m_Regions;
	};

}