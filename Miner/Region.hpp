#pragma once

#include "Tile.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace Miner {

	class Region {
	public:
		Region();
		Region(unsigned int _width, unsigned int _height);
		~Region();

		void update(float _delta);
		void handleEvent(sf::Event _event);
		void draw(sf::RenderTarget & _target, sf::RenderStates _states) const;

		static const float TickRate;

	private:
		float m_AccumulatedTime;

		std::vector<Tile *> m_Tiles;

		unsigned int m_Width;
		unsigned int m_Height;
	};

}