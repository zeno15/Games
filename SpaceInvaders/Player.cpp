#include "Player.hpp"

#include "../Common/InstanceCollection.hpp"
#include "ProjectileManager.hpp"
#include "Projectile.hpp"
#include "GameBoard.hpp"

namespace SpaceInvaders {

	const float Player::Width = 60.0f;
	const float Player::Height = 20.0f;

	Player::Player() {
		m_Basic.setSize(sf::Vector2f(Width, Height));
		m_Basic.setFillColor(sf::Color::Yellow);
		m_Basic.setOrigin(Width / 2.0f, 0.0f);
		m_HorizontalOffset = GameBoard::GameWidth / 2.0f;
	}


	Player::~Player() {}

	void Player::update(float _delta) {
		float movement = 0.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement -= 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement += 1.0f;
		}
	
		float speed = 64.0f * 4.0f;

		float xOffset = speed * movement * _delta;
		m_HorizontalOffset += xOffset;


		if (m_HorizontalOffset < Width / 2.0f) {
			m_HorizontalOffset = Width / 2.0f;
		}
		if (m_HorizontalOffset > GameBoard::GameWidth - Width / 2.0f) {
			m_HorizontalOffset = GameBoard::GameWidth - Width / 2.0f;
		}
	}

	void Player::handleEvent(sf::Event _event) {
		if (_event.type == sf::Event::KeyPressed) {
			if (_event.key.code == sf::Keyboard::Space) {
				auto p = new Projectile(sf::Vector2f(m_HorizontalOffset, GameBoard::GameHeight - Height - 8.0f), sf::Vector2f(0.0f, -1.0f), 256.0f);
				Common::InstanceCollection::getInstance<ProjectileManager>().addProjectile(p);
			}
		}
	}

	void Player::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		_states.transform.translate(m_HorizontalOffset, -Height);
		_target.draw(m_Basic, _states);
	}

}