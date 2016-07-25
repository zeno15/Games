#include "GameScene.hpp"

namespace Miner {

	GameScene::GameScene(void) :
		Scene("GameScene") {

	}
	GameScene::~GameScene(void) {

	}

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