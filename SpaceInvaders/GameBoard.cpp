#include "GameBoard.hpp"

#include "../Common/InstanceCollection.hpp"
#include "ProjectileManager.hpp"

namespace SpaceInvaders {

	const float GameBoard::GameHeight = 600.0f;
	const float GameBoard::GameWidth = 450.0f;
	const float GameBoard::GameBorderSize = 2.0f;

	GameBoard::GameBoard() :
		m_Horde(4, 6) {
		m_Bounds.setFillColor(sf::Color::Blue);
		m_Bounds.setOutlineColor(sf::Color::Red);
		m_Bounds.setOutlineThickness(GameBorderSize);

		m_Bounds.setSize(sf::Vector2f(GameWidth, GameHeight));
		m_Bounds.setOrigin(0.0f, GameHeight);

		m_Player = new Player();		
	}


	GameBoard::~GameBoard() {}

	void GameBoard::update(float _delta) {
		m_Player->update(_delta);

		m_Horde.update(_delta);

		Common::InstanceCollection::getInstance<ProjectileManager>().update(_delta);
	}

	void GameBoard::handleEvent(sf::Event _event) {
		m_Player->handleEvent(_event); 

		m_Horde.handleEvent(_event);
		Common::InstanceCollection::getInstance<ProjectileManager>().handleEvent(_event);
	}

	void GameBoard::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		_target.draw(m_Bounds, _states);
		_target.draw(*m_Player, _states);

		_states.transform.translate(sf::Vector2f(0.0f, -GameHeight));

		_target.draw(m_Horde, _states);
		_target.draw(Common::InstanceCollection::getInstance<ProjectileManager>(), _states);
	}

}