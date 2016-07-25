#include "WanderingCharacter.hpp"

#include "Tile.hpp"

#include <cstdlib>

namespace Pokemon {

	WanderingCharacter::WanderingCharacter() :
	m_AccumulatedTime(0.0f) {
		refreshWanderTime(2.5f, 5.0f);
	}


	WanderingCharacter::~WanderingCharacter() {}

	void WanderingCharacter::update(float _delta) {
		Character::update(_delta);

		m_AccumulatedTime += _delta;

		if (m_AccumulatedTime >= m_WanderTime) {
			m_AccumulatedTime -= m_WanderTime;
			refreshWanderTime(0.5f, 2.0f);
			moveRandomDirection();
		}
	}
	void WanderingCharacter::handleEvent(sf::Event _event) {}
	void WanderingCharacter::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		float rad = Tile::Width * 3.0f / 4.0f / 2.0f;
		sf::Vector2f p = sf::Vector2f(Tile::Width * m_Position.x, Tile::Height * m_Position.y) + sf::Vector2f(Tile::Width, Tile::Height) / 2.0f;
		sf::CircleShape c(rad);
		c.setFillColor(sf::Color::Blue);
		c.setOrigin(rad, rad);
		c.setPosition(p);
		_target.draw(c, _states);

		sf::CircleShape facing(4.0f);
		facing.setOrigin(4.0f, 4.0f);
		facing.setFillColor(sf::Color::Green);
		facing.setPosition(p + Common::Orientation::directionToVector(m_Direction) * rad);
		_target.draw(facing, _states);
	}

	void WanderingCharacter::refreshWanderTime(float _min, float _max) {

		int range = static_cast<int>((_max - _min) * 100);

		m_WanderTime = (static_cast<float>(rand() % range) + _min * 100.0f) / 100.0f;
	}
	void WanderingCharacter::moveRandomDirection(void) {
		auto d = static_cast<Common::Orientation::Direction>(rand() % 4);
		face(d);
		move(d);
	}
}