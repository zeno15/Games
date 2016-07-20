#pragma once

#include "../Common/Entity.hpp"

namespace SpaceInvaders {
	class Projectile : public Common::Entity {
	public:
		Projectile(const sf::Vector2f& _position, const sf::Vector2f& _direction, float _speed);
		~Projectile();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		sf::FloatRect getBounds(void) const;

		bool isAlive(void) const;
		void kill(void);

		sf::Vector2f getPosition(void) const;

	private:
		sf::Vector2f m_Position;
		sf::Vector2f m_Direction;
		float m_Speed;

		bool m_Alive;
	};

}