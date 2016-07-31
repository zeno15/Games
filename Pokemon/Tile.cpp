#include "Tile.hpp"

#include <iostream>

#include "../Common/InstanceCollection.hpp"
#include "../Common/TextureManager.hpp"

namespace Pokemon {
	const float Tile::Width = 32.0f;
	const float Tile::Height = 32.0f;

	Tile::Tile(unsigned int _x, unsigned int _y, unsigned int _spritesheetX, unsigned int _spritesheetY, bool _isRegionJumper /*= false*/) :
		m_X(_x),
		m_Y(_y),
		m_SpriteSheetX(_spritesheetX),
		m_SpriteSheetY(_spritesheetY),
		m_IsFree(true),
		m_IsRegionJumper(_isRegionJumper) {
		
		m_Sprite.setTexture(Common::InstanceCollection::getInstance<Common::TextureManager>().getTexture("Tiles"));
		m_Sprite.setTextureRect(sf::IntRect(_spritesheetX * Width, _spritesheetY * Height, Width, Height));
		m_Sprite.setPosition(sf::Vector2f(m_X * Width, m_Y * Height));
	}


	Tile::~Tile() {}

	void Tile::update(float _delta) {
	}

	void Tile::handleEvent(sf::Event _event) {
	}

	void Tile::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		//_target.draw(m_Graphics, _states);
		_target.draw(m_Sprite, _states);
	}

	void Tile::onEntityEntered(RegionEntity *_entity) {

	}
	void Tile::onEntityLeave(RegionEntity *_entity) {

	}
	void Tile::onEntityMovedWithin(RegionEntity *_entity) {

	}

	unsigned int Tile::getX(void) const {
		return m_X;
	}
	unsigned int Tile::getY(void) const {
		return m_Y;
	}

	bool Tile::isRegionJumper(void) const {
		return m_IsRegionJumper;
	}
	bool Tile::isFree(void) const {
		return m_IsFree;
	}
	void Tile::reserve(void) {
		m_IsFree = false;
	}
	void Tile::free(void) {
		m_IsFree = true;
	}
}