#include "GameScene.hpp"

#include "../Common/InstanceCollection.hpp"
#include "../Common/FontManager.hpp"
#include "NotificationManager.hpp"
#include <SFML\Graphics.hpp>
#include <functional>

namespace MineSweeper {

	GameScene::GameScene() :
		Scene("GameScene"),
		m_State(State::Playing) {

		Common::InstanceCollection::getInstance<NotificationManager>().NotifyWin = std::bind(&GameScene::onWin, this);
		Common::InstanceCollection::getInstance<NotificationManager>().NotifyLoss = std::bind(&GameScene::onLoss, this);

		m_WonMessage = sf::Text("You won! press enter to start again", Common::InstanceCollection::getInstance<Common::FontManager>().getFont("arial"));
		m_LostMessage = sf::Text("You lost! press enter to try again", Common::InstanceCollection::getInstance<Common::FontManager>().getFont("arial"));

		m_Board = new GameBoard(20, 20, 20);
	}


	GameScene::~GameScene() {}

	void GameScene::update(float _delta) {
		m_Board->update(_delta);
	}

	void GameScene::handleEvent(const sf::Event & _event) {
		if (m_State == State::Playing) {
			m_Board->handleEvent(_event);
		}
		if (m_State == State::Lost || m_State == State::Won) {
			if (_event.type == sf::Event::KeyPressed) {
				if (_event.key.code == sf::Keyboard::Return) {
					reset(20, 20, m_Board->getTotalMines());
					m_State = State::Playing;
				}
			}
		}
	}

	void GameScene::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		_target.draw(*m_Board, _states);

		if (m_State == State::Lost) {
			_target.draw(m_LostMessage, _states);
		}
		else if (m_State == State::Won) {
			_target.draw(m_WonMessage, _states);
		}
	}

	void GameScene::reset(unsigned int _width, unsigned int _height, int _mines) {
		delete m_Board;
		m_Board = new GameBoard(_width, _height, _mines);
	}


	void GameScene::onWin(void) {
		m_State = State::Won;
	}
	void GameScene::onLoss(void) {
		m_State = State::Lost;
	}

}