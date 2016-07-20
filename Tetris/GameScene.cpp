#include "GameScene.hpp"

namespace Tetris {

	GameScene::GameScene(void) :
	Scene("GameScene") {

	}
	GameScene::~GameScene(void) {

	}

	void GameScene::update(float _delta) {
	}
	void GameScene::handleEvent(const sf::Event & _event) {
	}
	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::CircleShape c(48.0f);
		_target.draw(c, _states);
	}
}