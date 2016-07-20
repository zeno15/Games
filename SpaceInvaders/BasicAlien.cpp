#include "BasicAlien.hpp"

#include "../Common/ColourUtility.hpp"

namespace SpaceInvaders {

	const float BasicAlien::BoundingWidth = 48;
	const float BasicAlien::BoundingHeight = 48;
	const float BasicAlien::SpacingWidth = 8;
	const float BasicAlien::SpacingHeight = 8;

	BasicAlien::BasicAlien(AlienType _type) :
	m_Alive(true),
	m_Type(_type) {}

	BasicAlien::~BasicAlien() {}


	void BasicAlien::update(float _delta) {}

	void BasicAlien::handleEvent(sf::Event _event) {}

	void BasicAlien::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::CircleShape c(BoundingWidth / 3.0f);
		sf::Color col;
		if (m_Type == AlienType::Large) {
			col = sf::Color::Yellow;
		}
		else if (m_Type == AlienType::Medium) {
			col = sf::Color::Cyan;
		}
		else if (m_Type == AlienType::Small) {
			col = sf::Color::Green;
		}
		c.setFillColor(col);
		c.setOrigin(BoundingWidth / 3.0f, BoundingWidth / 3.0f);
		_target.draw(c, _states);
	}

	bool BasicAlien::isAlive(void) const {
		return m_Alive;
	}

	void BasicAlien::kill(void) {
		m_Alive = false;
	}
	BasicAlien::AlienType BasicAlien::getType(void) const {
		return m_Type;
	}
}