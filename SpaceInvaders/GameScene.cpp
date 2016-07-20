#include "GameScene.hpp"

#include "../Common/InstanceCollection.hpp"
#include "../Common/Application.hpp"
#include "NotificationManager.hpp"

#include <iostream>

namespace SpaceInvaders  {

	GameScene::GameScene() :
	Scene("GameScene") {
		m_Board = new GameBoard();

		Common::InstanceCollection::getInstance<NotificationManager>().NotifyPlayerWon = std::bind(&GameScene::onPlayerWon, this);
		Common::InstanceCollection::getInstance<NotificationManager>().NotifyPlayerLost = std::bind(&GameScene::onPlayerLost, this);
	}


	GameScene::~GameScene() {}

	void GameScene::update(float _delta) {
		if (m_Board != nullptr) {
			m_Board->update(_delta);
		}
	}

	void GameScene::handleEvent(const sf::Event & _event) {
		if (m_Board != nullptr) {
			m_Board->handleEvent(_event);
		}
	}

	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		if (m_Board != nullptr) {
			auto windowSize = sf::Vector2f(Common::InstanceCollection::getInstance<Common::Application>().getWindow().getSize());

			float yMovement = windowSize.y - GameBoard::GameBorderSize * 2.0f;
			float xMovement = windowSize.x / 2.0f - (GameBoard::GameWidth + GameBoard::GameBorderSize * 2.0f) / 2.0f;

			_states.transform.translate(sf::Vector2f(xMovement, yMovement));

			_target.draw(*m_Board, _states);

		}
	}

	void GameScene::onPlayerWon(void) {
		std::cout << "GameScene::PlayerWon" << std::endl;
	}
	void GameScene::onPlayerLost(void) {
		std::cout << "GameScene::PlayerLost" << std::endl;
	}
}