#pragma once

#include "MobileEntity.hpp"
#include "../Common/Orientation.hpp"

namespace Survival {

	class Player : public MobileEntity {
	public:
		Player();
		~Player();

		// Inherited via MobileEntity
		virtual void update(float _delta) override;
		virtual void updateTick(void) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	protected:
		sf::Vector2f m_Position;
		sf::Vector2f m_TargetPosition;
		Common::Orientation::Direction m_Direction;
	};

}