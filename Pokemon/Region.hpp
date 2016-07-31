#pragma once

#include <string>
#include <vector>

#include "RegionEntity.hpp"

#include "Tile.hpp"

namespace Pokemon {

	class JSON;
	class Region : public Common::Entity {
	public:
		Region(const std::string& _name);
		Region(const std::string& _name, unsigned int _width, unsigned int _height);
		Region(const std::string& _name, const std::string& _filename);
		~Region();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		Tile& getTile(unsigned int _x, unsigned int _y);
		const Tile& getTile(unsigned int _x, unsigned int _y) const;

		bool canMoveTo(int _x, int _y, RegionEntity *_entity = nullptr) const;

		const std::string& getName(void) const;

		void addEntity(RegionEntity *_entity);
		void removeEntity(RegionEntity *_entity);

	private:
		void loadFromFile(const std::string& _filename);
		Tile *createTileFromColor(const sf::Color& _color, unsigned int _x, unsigned int _y);

		Tile *loadTileFromEntity(JSON& _jsonEntity, sf::Vector2u& _coordinates);

	private:
		std::vector<Tile *> m_Tiles;
		std::vector<RegionEntity *> m_Entities;

		std::vector<RegionEntity *> m_EntitiesToAdd;
		std::vector<RegionEntity *> m_EntitiesToRemove;


		unsigned int m_Width;
		unsigned int m_Height;

		std::string m_Name;
	};

}