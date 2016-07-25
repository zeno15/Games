#pragma once


#include <SFML/Graphics.hpp>

namespace Survival {

	class Entity;
	class Tile {
	public:
		Tile(unsigned int _x, unsigned int _y);
		~Tile();

		void update(float _delta);
		void updateTick(void);
		void handleEvent(sf::Event _event);
		void draw(sf::RenderTarget & _target, sf::RenderStates _states) const;

		unsigned int getX(void) const;
		unsigned int getY(void) const;

		static const float Width;
		static const float Height;

		Entity *getEntity(void);
		void setEntity(Entity *_entity);

		bool holdsPressure(void) const;
		void setHoldsPressure(bool _holdsPressure);

		bool hasEntity(void) const;

	private:
		void updated(void);

	private:
		unsigned int m_X;
		unsigned int m_Y;

		bool m_HoldsPressure;

		Entity *m_Entity;

		sf::RectangleShape m_Graphics;
	};

}