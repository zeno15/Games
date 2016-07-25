#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Room.hpp"
#include "MobileEntity.hpp"

namespace Survival {

	class Tile;
	class Level {
	public:
		Level();
		Level(unsigned int _width, unsigned int _height);
		~Level();

		void update(float _delta);
		void handleEvent(sf::Event _event);
		void draw(sf::RenderTarget & _target, sf::RenderStates _states) const;

		unsigned int getWidth(void) const;
		unsigned int getHeight(void) const;

		static const unsigned int MinimumWidth;
		static const unsigned int MinimumHeight;
		static const float TickRate;


		Tile& getTile(unsigned int _x, unsigned int _y);
		const Tile& getTile(unsigned int _x, unsigned int _y) const;
		bool isTileAt(int _x, int _y) const;
		bool canMoveToTileAt(int _x, int _y) const;
		Entity *getTileEntityAt(int _x, int _y);

	private:
		void onTileUpdated(unsigned int _x, unsigned int _y);
		void onGhostBuilt(unsigned int _x, unsigned int _y);

		void handleNewHoldsPressureTile(unsigned int _x, unsigned int _y);

	private:
		void generateTiles(void);

	private:
		unsigned int m_Width;
		unsigned int m_Height;

		std::vector<Tile *> m_Tiles;
		std::vector<Room> m_Rooms;
		std::vector<MobileEntity *> m_MobileEntities;
		Room m_OutsideRoom;

		float m_AccumulatedTime;
	};

}