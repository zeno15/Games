#include "GameScene.hpp"

#include "../Common/InstanceCollection.hpp"
#include "RegionManager.hpp"

namespace Pokemon {

	GameScene::GameScene() :
		Scene("GameScene"),
		m_Region("StartRegion") {
		Common::InstanceCollection::getInstance<RegionManager>().setCurrentRegion(&m_Region);
	}


	GameScene::~GameScene() {}

	void GameScene::update(float _delta) {
		m_Region.update(_delta);
	}

	void GameScene::handleEvent(const sf::Event & _event) {
		m_Region.handleEvent(_event);
	}

	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		m_Region.draw(_target, _states);
	}

}