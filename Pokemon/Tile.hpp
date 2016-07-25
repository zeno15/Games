#pragma once

#include "../Common/Entity.hpp"

namespace Pokemon {


	class Tile : public Common::Entity {
	public:
		static const float Width;
		static const float Height;

		Tile(unsigned int _x, unsigned int _y);
		~Tile();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		virtual void onEntityEntered(Entity *_entity);
		virtual void onEntityLeave(Entity *_entity);
		virtual void onEntityMovedWithin(Entity *_entity);

		unsigned int getX(void) const;
		unsigned int getY(void) const;

		bool isFree(void) const;
		void reserve(void);
		void free(void);

		void setFillColor(const sf::Color& _color);

	private:
		unsigned int m_X;
		unsigned int m_Y;

		bool m_IsFree;

		sf::RectangleShape m_Graphics;
	};

}