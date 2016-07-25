#include "Airlock.hpp"

#include "Tile.hpp"

namespace Survival {

	Airlock::Airlock() :
	StationaryEntity(true, false) {}


	Airlock::~Airlock() {}

	void Survival::Airlock::update(float _delta) {}

	void Survival::Airlock::updateTick(void) {}

	void Survival::Airlock::handleEvent(sf::Event _event) {}

	void Survival::Airlock::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::RectangleShape r = sf::RectangleShape(sf::Vector2f(Tile::Width * 3, Tile::Height));
		auto c = sf::Color::Cyan;
		c.a = static_cast<unsigned int>(m_Alpha * 255);
		r.setFillColor(c);
		r.setOrigin(sf::Vector2f(Tile::Width * 3, Tile::Height) / 2.0f);
		_target.draw(r, _states);
	}

}