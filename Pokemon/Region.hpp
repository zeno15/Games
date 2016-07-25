#pragma once

#include <string>
#include <vector>

#include "../Common/Entity.hpp"

#include "Tile.hpp"

namespace Pokemon {

	class Region : public Common::Entity {
	public:
		Region(const std::string& _name);
		Region(const std::string& _name, unsigned int _width, unsigned int _height);
		~Region();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		Tile& getTile(unsigned int _x, unsigned int _y);
		const Tile& getTile(unsigned int _x, unsigned int _y) const;

		bool canMoveTo(int _x, int _y) const;

		const std::string& getName(void) const;

	private:
		std::vector<Tile *> m_Tiles;
		std::vector<Common::Entity *> m_Entities;

		unsigned int m_Width;
		unsigned int m_Height;

		std::string m_Name;
	};

}