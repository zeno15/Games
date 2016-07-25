#include "Tile.hpp"

#include <iostream>

namespace Pokemon {
	const float Tile::Width = 32.0f;
	const float Tile::Height = 32.0f;

	Tile::Tile(unsigned int _x, unsigned int _y) :
		m_X(_x),
		m_Y(_y),
		m_IsFree(true) {
		float thicknesss = 1.0f;
		m_Graphics = sf::RectangleShape(sf::Vector2f(Width - thicknesss * 2, Height - thicknesss * 2));
		m_Graphics.setPosition(sf::Vector2f(m_X * Width, m_Y * Height));
		m_Graphics.setOutlineColor(m_IsFree ? sf::Color::Green : sf::Color::Red);
		m_Graphics.setFillColor(sf::Color(56, 56, 56));
		m_Graphics.setOutlineThickness(thicknesss);
		m_Graphics.setOrigin(-thicknesss, -thicknesss);
	}


	Tile::~Tile() {}

	void Tile::update(float _delta) {
	}

	void Tile::handleEvent(sf::Event _event) {
	}

	void Tile::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		_target.draw(m_Graphics, _states);
	}

	void Tile::onEntityEntered(Entity *_entity) {

	}
	void Tile::onEntityLeave(Entity *_entity) {

	}
	void Tile::onEntityMovedWithin(Entity *_entity) {

	}

	unsigned int Tile::getX(void) const {
		return m_X;
	}
	unsigned int Tile::getY(void) const {
		return m_Y;
	}

	bool Tile::isFree(void) const {
		return m_IsFree;
	}
	void Tile::reserve(void) {
		m_IsFree = false;
		m_Graphics.setOutlineColor(m_IsFree ? sf::Color::Green : sf::Color::Red);
	}
	void Tile::free(void) {
		m_IsFree = true;
		m_Graphics.setOutlineColor(m_IsFree ? sf::Color::Green : sf::Color::Red);
	}
	void Tile::setFillColor(const sf::Color& _color) {
		m_Graphics.setFillColor(_color);
	}
}