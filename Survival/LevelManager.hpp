#pragma once

#include "../Common/Manager.hpp"
#include <SFML/Graphics.hpp>

namespace Common {
	class InstanceCollection;
}

namespace Survival {

	class Level;
	class LevelManager : public Common::Manager {
	public:
		friend class Common::InstanceCollection;

		const static std::string Name;

		void setCurrentLevel(Level *_level);
		Level *getCurrentLevel(void);

	private:
		LevelManager();
		~LevelManager();

		Level *m_CurrentLevel;
	};

}