#pragma once

#include "../Common/Entity.hpp"
#include "../Common/Orientation.hpp"

namespace Pokemon {

	class Character : public Common::Entity {
	public:
		Character();
		~Character();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const = 0;

		void face(Common::Orientation::Direction _direction);
		void move(Common::Orientation::Direction _direction);

	protected:
		sf::Vector2f m_Position;
		sf::Vector2f m_TargetPosition;
		Common::Orientation::Direction m_Direction;
	};

}