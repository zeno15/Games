#include "Player.hpp"

#include "Tile.hpp"

namespace Pokemon {

	Player::Player() :
	Character(true) {}


	Player::~Player() {}

	void Player::update(float _delta) {
		Character::update(_delta);
	}
	void Player::handleEvent(sf::Event _event) {
		Character::handleEvent(_event);
		if (_event.type == sf::Event::KeyPressed) {
			if (m_Position == m_TargetPosition) {
				if (_event.key.code == sf::Keyboard::Left || _event.key.code == sf::Keyboard::A) {
					move(Common::Orientation::Direction::West);
				}
				else if (_event.key.code == sf::Keyboard::Right || _event.key.code == sf::Keyboard::D) {
					move(Common::Orientation::Direction::East);
				}
				else if (_event.key.code == sf::Keyboard::Up || _event.key.code == sf::Keyboard::W) {
					move(Common::Orientation::Direction::North);
				}
				else if (_event.key.code == sf::Keyboard::Down || _event.key.code == sf::Keyboard::S) {
					move(Common::Orientation::Direction::South);
				}
			}
		}
	}
	void Player::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		float rad = Tile::Width * 3.0f / 4.0f / 2.0f;
		sf::CircleShape c(rad);
		c.setOrigin(rad, rad);
		c.setPosition(sf::Vector2f(Tile::Width * m_Position.x, Tile::Height * m_Position.y) + sf::Vector2f(Tile::Width, Tile::Height) / 2.0f);
		_target.draw(c, _states);

		sf::CircleShape facing(4.0f);
		facing.setOrigin(4.0f, 4.0f);
		facing.setFillColor(sf::Color::Green);
		facing.setPosition(c.getPosition() + Common::Orientation::directionToVector(m_Direction) * rad);
		_target.draw(facing, _states);
	}

}