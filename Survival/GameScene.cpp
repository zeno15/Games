#include "GameScene.hpp"

#include "../Common/Application.hpp"
#include "../Common/InstanceCollection.hpp"
#include "NotificationManager.hpp"
#include "BuildingManager.hpp"
#include "LevelManager.hpp"

#include "Wall.hpp"
#include "Tile.hpp"

#include "EntityGhost.hpp"

#include <iostream>

namespace Survival {

	GameScene::GameScene() :
	Scene("GameScene") {
		Common::InstanceCollection::getInstance<LevelManager>().setCurrentLevel(&m_Level);
	}


	GameScene::~GameScene() {}

	void GameScene::update(float _delta) {
		m_Level.update(_delta);
	}

	void GameScene::handleEvent(const sf::Event & _event) {
		m_Level.handleEvent(_event);

		auto& notification = Common::InstanceCollection::getInstance<NotificationManager>();
		auto& building = Common::InstanceCollection::getInstance<BuildingManager>();

		if (_event.type == sf::Event::KeyReleased) {
			if (_event.key.code == sf::Keyboard::Escape) {
				building.resetBuildMode();
				std::cout << "Building Nothing" << std::endl;
			}
			else if (_event.key.code == sf::Keyboard::Num1) {
				if (building.getCurrentBuildMode() == BuildingManager::BuildMode::Wall) {
					building.resetBuildMode();
					std::cout << "Building Nothing" << std::endl;
				}
				else {
					building.ActivateBuildWallMode();
					std::cout << "Building Wall" << std::endl;
				}
			}
		}

		if (building.getCurrentBuildMode() != BuildingManager::BuildMode::None) {
			if (_event.type == sf::Event::MouseButtonPressed) {
				auto p = sf::Vector2f(sf::Mouse::getPosition(Common::InstanceCollection::getInstance<Common::Application>().getWindow()));

				int x = static_cast<int>(p.x) / static_cast<int>(Tile::Width);
				int y = static_cast<int>(p.y) / static_cast<int>(Tile::Height);

				if (p.x > 0.0f && p.y > 0.0f && x < static_cast<int>(m_Level.getWidth()) && y < static_cast<int>(m_Level.getHeight())) {
					auto& tile = m_Level.getTile(x, y);
					if (!tile.hasEntity()) {
						auto r = ResourceCollection();

						r.addResource(ResourceCollection::Resource(ResourceCollection::Resource::WorkName, 2));
						auto wallGhost = new EntityGhost(new Wall(), r);
						tile.setEntity(wallGhost);
					}
				}
			}
		}

	}

	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		m_Level.draw(_target, _states);
	}

}