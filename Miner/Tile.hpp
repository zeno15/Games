#pragma once

#include "Entity.hpp"

namespace Miner {

	class Tile : public Entity {
	public:
		static const float Width;
		static const float Height;

		Tile(unsigned int _x, unsigned int _y);
		~Tile();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void updateTick(void) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;


		unsigned int getX(void) const;
		unsigned int getY(void) const;

		bool hasEntity(void) const;
		void setEntity(Entity *_entity);
		Entity *getEntity(void);

	private:
		unsigned int m_X;
		unsigned int m_Y;

		Entity *m_Entity;

		sf::RectangleShape m_Graphics;
	};

}