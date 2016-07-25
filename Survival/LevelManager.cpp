#include "LevelManager.hpp"


namespace Survival {

	const std::string LevelManager::Name = "LevelManager";

	LevelManager::LevelManager() :
		m_CurrentLevel(nullptr) {}
	
	LevelManager::~LevelManager() {}


	void LevelManager::setCurrentLevel(Level *_level) {
		m_CurrentLevel = _level;
	}
	Level *LevelManager::getCurrentLevel(void) {
		return m_CurrentLevel;
	}
}