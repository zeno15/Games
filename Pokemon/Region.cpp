#include "Region.hpp"

#include "Player.hpp"
#include "WanderingCharacter.hpp"

#include "RegionJumper.hpp"
#include "JSON.hpp"

#include <iostream>

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
				m_Tiles.emplace_back(new Tile(x, y, 0, 0));
			}
		}

		unsigned jumpX = 18;
		unsigned jumpY = 18;

		m_Entities.push_back(new Player());
		for (unsigned int i = 0; i < 10; i += 1) {
			m_Entities.push_back(new WanderingCharacter());
		}
	}
	Region::Region(const std::string& _name, const std::string& _filename) :
	m_Name(_name) {
		loadFromFile(_filename);
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

		if (m_EntitiesToRemove.size()) {
			for (auto e : m_EntitiesToRemove) {
				for (unsigned int i = 0; i < m_Entities.size(); i += 1) {
					if (e == m_Entities[i]) {
						m_Entities.erase(m_Entities.begin() + i);
						break;
					}
				}
			}
			m_EntitiesToRemove.clear();
		}

		if (m_EntitiesToAdd.size()) {
			for (auto e : m_EntitiesToAdd) {
				m_Entities.push_back(e);
			}
			m_EntitiesToAdd.clear();
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
	void Region::addEntity(RegionEntity *_entity) {
		m_EntitiesToAdd.push_back(_entity);
	}
	void Region::removeEntity(RegionEntity *_entity) {
		m_EntitiesToRemove.push_back(_entity);
	}

	Tile& Region::getTile(unsigned int _x, unsigned int _y) {
		return *m_Tiles[_y * m_Width + _x];
	}
	const Tile& Region::getTile(unsigned int _x, unsigned int _y) const {
		return *m_Tiles[_y * m_Width + _x];
	}

	bool Region::canMoveTo(int _x, int _y, RegionEntity *_entity /*= nullptr*/) const {
		if (_x < 0 || _y < 0 || _x >= static_cast<int>(m_Width) || _y >= static_cast<int>(m_Height)) {
			return false;
		}

		auto& t = getTile(static_cast<unsigned int>(_x), static_cast<unsigned int>(_y));

		if (_entity != nullptr) {
			if (!_entity->canJumpRegions() && t.isRegionJumper()) {
				return false;
			}
		}

		return t.isFree();
	}
	const std::string& Region::getName(void) const {
		return m_Name;
	}
	void Region::loadFromFile(const std::string& _filename) {
		std::cout << "Loading level " << _filename << std::endl;

		std::cout << "Parsing region file: " << _filename << std::endl;
		auto levelData = JSON::LoadFromFile(_filename + ".json");

		std::cout << std::endl;
		std::cout << "Region name: '" << levelData["RegionName"] << "'" << std::endl;
		std::cout << "Width: " << levelData["Width"] << std::endl;
		std::cout << "Height: " << levelData["Height"] << std::endl;


		m_Width = static_cast<unsigned int>(levelData["Width"].ToInt());
		m_Height = static_cast<unsigned int>(levelData["Height"].ToInt());



		auto& entities = levelData["Entities"];
		for (int i = 0; i < entities.size(); i += 1) {
			auto& e = entities[i];
			sf::Vector2u coords;
			m_Tiles.push_back(loadTileFromEntity(e, coords));
		}
	}
	Tile *Region::createTileFromColor(const sf::Color& _color, unsigned int _x, unsigned int _y) {
		return new Tile(_x, _y, 0, 0);
	}
	Tile *Region::loadTileFromEntity(JSON& _jsonEntity, sf::Vector2u& _coordinates) {

		auto x = static_cast<unsigned int>(_jsonEntity["RegionX"].ToInt());
		auto y = static_cast<unsigned int>(_jsonEntity["RegionY"].ToInt());

		Tile *t = nullptr;

		auto spriteX = static_cast<unsigned int>(_jsonEntity["SpriteSheetIndexX"].ToInt());
		auto spriteY = static_cast<unsigned int>(_jsonEntity["SpriteSheetIndexY"].ToInt());

		if (_jsonEntity["IsRegionJumper"].ToBool()) {
			t = new RegionJumper(x, y, spriteX, spriteY, _jsonEntity["TargetRegionName"].ToString(), _jsonEntity["TargetRegionX"].ToInt(), _jsonEntity["TargetRegionY"].ToInt());
		}
		else {
			t = new Tile(x, y, spriteX, spriteY);
		}

		return t;
	}
}