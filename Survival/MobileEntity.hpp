#pragma once

#include "Entity.hpp"

namespace Survival {

	class MobileEntity : public Entity {
	public:
		MobileEntity();
		~MobileEntity();

		virtual void update(float _delta) = 0;
		virtual void updateTick(void) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const = 0;
	};

}