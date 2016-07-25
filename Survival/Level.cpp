#include "Level.hpp"

#include "Tile.hpp"
#include "Player.hpp"
#include "NotificationManager.hpp"
#include "EntityGhost.hpp"
#include "../Common/InstanceCollection.hpp"

#include <iostream>

namespace Survival {


	const unsigned int Level::MinimumWidth = 20;
	const unsigned int Level::MinimumHeight = 20;
	const float Level::TickRate = 1.0f;

	Level::Level() :
		Level(MinimumWidth, MinimumHeight) {
		m_MobileEntities.push_back(new Player());
	}

	Level::Level(unsigned int _width, unsigned int _height) :
		m_Width(_width),
		m_Height(_height),
		m_AccumulatedTime(0.0f),
		m_OutsideRoom(sf::Vector2u(), sf::Vector2u(_width, _height)) {
		if (m_Width < MinimumWidth) {
			m_Width = MinimumWidth;
		}
		if (m_Height < MinimumHeight) {
			m_Height = MinimumHeight;
		}

		auto& n = Common::InstanceCollection::getInstance<NotificationManager>();
		n.tileUpdated = std::bind(&Level::onTileUpdated, this, std::placeholders::_1, std::placeholders::_2);
		n.ghostBuiltAt = std::bind(&Level::onGhostBuilt, this, std::placeholders::_1, std::placeholders::_2);

		generateTiles();
	}

	Level::~Level() {
		for (auto t : m_Tiles) {
			delete t;
		}
	}


	void Level::update(float _delta) {
		m_AccumulatedTime += _delta;
		for (auto t : m_Tiles) {
			t->update(_delta);
		}

		for (auto m : m_MobileEntities) {
			m->update(_delta);
		}

		if (m_AccumulatedTime >= TickRate) {
			m_AccumulatedTime -= TickRate;
			for (auto t : m_Tiles) {
				t->updateTick();
			}
			for (auto m : m_MobileEntities) {
				m->updateTick();
			}
		}
	}
	void Level::handleEvent(sf::Event _event) {
		for (auto t : m_Tiles) {
			t->handleEvent(_event);
		}
		for (auto m : m_MobileEntities) {
			m->handleEvent(_event);
		}
	}
	void Level::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		for (auto t : m_Tiles) {
			t->draw(_target, _states);
		}
		for (auto m : m_MobileEntities) {
			m->draw(_target, _states);
		}
	}

	unsigned int Level::getWidth(void) const {
		return m_Width;
	}
	unsigned int Level::getHeight(void) const {
		return m_Height;
	}


	Tile& Level::getTile(unsigned int _x, unsigned int _y) {
		return *m_Tiles[_y * m_Width + _x];
	}
	const Tile& Level::getTile(unsigned int _x, unsigned int _y) const {
		return *m_Tiles[_y * m_Width + _x];
	}

	void Level::generateTiles(void) {
		for (unsigned int y = 0; y < m_Height; y += 1) {
			for (unsigned int x = 0; x < m_Width; x += 1) {
				m_Tiles.push_back(new Tile(x, y));
			}
		}
	}
	void Level::onTileUpdated(unsigned int _x, unsigned int _y) {
		auto& t = getTile(_x, _y);
		if (t.hasEntity() && t.getEntity()->holdsPressure()) {
			handleNewHoldsPressureTile(_x, _y);
		}
	}
	void Level::onGhostBuilt(unsigned int _x, unsigned int _y) {
		auto& t = getTile(_x, _y);
		if (!t.hasEntity() || !t.getEntity()->isGhost()) {
			std::cout << "No ghost was found at " << _x << ", " << _y << std::endl;
			return;
		}

		auto ghost = dynamic_cast<EntityGhost *>(t.getEntity());
		ghost->changeAlpha(1.0f);
		t.setEntity(ghost->getCompleteEntity());
		t.getEntity()->changeAlpha(1.0f);
		delete ghost;
	}
	bool Level::isTileAt(int _x, int _y) const {
		return _x >= 0 && _y >= 0 && _x < static_cast<int>(m_Width) && _y < static_cast<int>(m_Height);
	}
	bool Level::canMoveToTileAt(int _x, int _y) const {
		if (!isTileAt(_x, _y)) {
			return false;
		}

		auto& t = getTile(static_cast<unsigned int>(_x), static_cast<unsigned int>(_y));

		if (!t.hasEntity()) {
			return true;
		}

		return false;
	}
	Entity *Level::getTileEntityAt(int _x, int _y) {
		if (!isTileAt(_x, _y)) {
			return false;
		}

 		auto& t = getTile(static_cast<unsigned int>(_x), static_cast<unsigned int>(_y));

		if (!t.hasEntity()) {
			return nullptr;
		}

		return t.getEntity();
	}
	void Level::handleNewHoldsPressureTile(unsigned int _x, unsigned int _y) {
		std::cout << "New holds pressure entity at " << _x << ", " << _y << std::endl;
	}
}