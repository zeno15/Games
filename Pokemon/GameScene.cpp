#include "GameScene.hpp"

#include "../Common/InstanceCollection.hpp"
#include "RegionManager.hpp"

#include "Player.hpp"
#include "WanderingCharacter.hpp"

namespace Pokemon {

	GameScene::GameScene() :
		Scene("GameScene"),
		m_Region("NewRegion", "../Resources/Pokemon/Regions/newRegion") {
		Common::InstanceCollection::getInstance<RegionManager>().addRegion(&m_Region);
		Common::InstanceCollection::getInstance<RegionManager>().addRegion(new Region("Region2", "../Resources/Pokemon/Regions/Region2"));
		Common::InstanceCollection::getInstance<RegionManager>().addRegion(new Region("Region3", "../Resources/Pokemon/Regions/Region3"));
		m_Region.addEntity(new Player());
		m_Region.addEntity(new WanderingCharacter());
		Common::InstanceCollection::getInstance<RegionManager>().setCurrentRegion(m_Region.getName());
	}


	GameScene::~GameScene() {}

	void GameScene::update(float _delta) {
		Common::InstanceCollection::getInstance<RegionManager>().getCurrentRegion()->update(_delta);
	}

	void GameScene::handleEvent(const sf::Event & _event) {
		Common::InstanceCollection::getInstance<RegionManager>().getCurrentRegion()->handleEvent(_event);
	}

	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		Common::InstanceCollection::getInstance<RegionManager>().getCurrentRegion()->draw(_target, _states);
	}

}