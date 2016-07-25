#include "BuildingManager.hpp"

#include "Wall.hpp"
#include "Airlock.hpp"

namespace Survival {

	const std::string BuildingManager::Name = "BuildingManager";

	BuildingManager::BuildingManager() :
	m_BuildMode(BuildMode::None) {}

	BuildingManager::~BuildingManager() {}


	BuildingManager::BuildMode BuildingManager::getCurrentBuildMode(void) const {
		return m_BuildMode;
	}
	void BuildingManager::resetBuildMode(void) {
		m_BuildMode = BuildMode::None;
	}

	void BuildingManager::ActivateBuildWallMode(void) {
		m_BuildMode = BuildMode::Wall;
	}
	void BuildingManager::ActivateBuildAirlockMode(void) {
		m_BuildMode = BuildMode::Airlock;
	}

	EntityGhost *BuildingManager::createGhost(BuildMode _mode) {
		auto r = ResourceCollection();
		switch (_mode) {
		case Survival::BuildingManager::None:
			return nullptr;
		case Survival::BuildingManager::Wall:
			
			r.addResource(ResourceCollection::Resource(ResourceCollection::Resource::WorkName, 2));
			return new EntityGhost(new Survival::Wall(), r);
		case Survival::BuildingManager::Airlock:
			break;
		default:
			return nullptr;
		}
	}
}