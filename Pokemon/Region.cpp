#include "Region.hpp"

#include "Player.hpp"
#include "WanderingCharacter.hpp"

#include "RegionJumper.hpp"

namespace Pokemon {


	Region::Region(const std::string& _name) :
		Region(_name, 20, 20) {

	}
	Region::Region(const std::string& _name, unsigned int _width, unsigned int _height) :
		m_Width(_width),
		m_Height(_height),
		m_Name(_name) {
		for (unsigned int y = 0; y < m_Height; y += 1) {
			for (unsigned int x = 0; x < m_Width; x += 1) {
				m_Tiles.emplace_back(new Tile(x, y));
			}
		}

		unsigned jumpX = 18;
		unsigned jumpY = 18;

		delete m_Tiles[jumpY * m_Width + jumpX];
		m_Tiles[jumpY * m_Width + jumpX] = new RegionJumper(jumpX, jumpY);

		m_Entities.push_back(new Player());
		for (unsigned int i = 0; i < 10; i += 1) {
			m_Entities.push_back(new WanderingCharacter());
		}
	}
	Region::~Region() {

	}

	void Region::update(float _delta) {
		for (auto& t : m_Tiles) {
			t->update(_delta);
		}
		for (auto& e : m_Entities) {
			e->update(_delta);
		}
	}

	void Region::handleEvent(sf::Event _event) {
		for (auto& t : m_Tiles) {
			t->handleEvent(_event);
		}
		for (auto& e : m_Entities) {
			e->handleEvent(_event);
		}
	}

	void Region::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		for (auto& t : m_Tiles) {
			t->draw(_target, _states);
		}
		for (auto& e : m_Entities) {
			e->draw(_target, _states);
		}
	}

	Tile& Region::getTile(unsigned int _x, unsigned int _y) {
		return *m_Tiles[_y * m_Width + _x];
	}
	const Tile& Region::getTile(unsigned int _x, unsigned int _y) const {
		return *m_Tiles[_y * m_Width + _x];
	}

	bool Region::canMoveTo(int _x, int _y) const {
		if (_x < 0 || _y < 0 || _x >= static_cast<int>(m_Width) || _y >= static_cast<int>(m_Height)) {
			return false;
		}

		auto& t = getTile(static_cast<unsigned int>(_x), static_cast<unsigned int>(_y));

		return t.isFree();
	}
	const std::string& Region::getName(void) const {
		return m_Name;
	}
}