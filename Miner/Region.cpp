#include "Region.hpp"

#include "MineralDeposit.hpp"

namespace Miner {

	const float Region::TickRate = 1.0f;

	Region::Region() :
	Region(20, 20) {

	}
	Region::Region(unsigned int _width, unsigned int _height) :
	m_Width(_width),
	m_Height(_height) {
		for (unsigned int y = 0; y < m_Height; y += 1) {
			for (unsigned int x = 0; x < m_Width; x += 1) {
				m_Tiles.push_back(new Tile(x, y));

				if ((x == 3 && y == 6) || (x == 16 && y == 12)) {
					m_Tiles.back()->setEntity(new MineralDeposit());
				}
			}
		}
	}
	Region::~Region() {}


	void Region::update(float _delta) {
		m_AccumulatedTime += _delta;

		for (auto& t : m_Tiles) {
			t->update(_delta);
		}

		if (m_AccumulatedTime >= TickRate) {
			m_AccumulatedTime -= TickRate;
			for (auto& t : m_Tiles) {
				t->updateTick();
			}
		}
	}
	void Region::handleEvent(sf::Event _event) {
		for (auto& t : m_Tiles) {
			t->handleEvent(_event);
		}
	}
	void Region::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		for (auto& t : m_Tiles) {
			t->draw(_target, _states);
		}
	}
}