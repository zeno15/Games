#pragma once

#include "../Common/Manager.hpp"
#include <SFML/Graphics.hpp>
#include "EntityGhost.hpp"

namespace Common {
	class InstanceCollection;
}

namespace Survival {

	class BuildingManager : public Common::Manager {
	public:
		enum BuildMode {
			None,
			Wall,
			Airlock
		};

		friend class Common::InstanceCollection;

		const static std::string Name;

		BuildMode getCurrentBuildMode(void) const;
		void resetBuildMode(void);

		void ActivateBuildWallMode(void);
		void ActivateBuildAirlockMode(void);

		static EntityGhost *createGhost(BuildMode _mode);

	private:
		BuildMode m_BuildMode;
	private:
		BuildingManager();
		~BuildingManager();
	};

}