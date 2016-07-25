#include "Wall.hpp"

#include "Tile.hpp"

namespace Survival {

	Wall::Wall() :
	StationaryEntity(true, false) {}


	Wall::~Wall() {}

	void Wall::update(float _delta) {}

	void Wall::updateTick(void) {}

	void Wall::handleEvent(sf::Event _event) {}

	void Wall::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::RectangleShape r = sf::RectangleShape(sf::Vector2f(Tile::Width, Tile::Height));
		auto c = sf::Color::Magenta;
		c.a = static_cast<unsigned int>(m_Alpha * 255);
		r.setFillColor(c);
		r.setOrigin(sf::Vector2f(Tile::Width, Tile::Height) / 2.0f);
		_target.draw(r, _states);
	}

}