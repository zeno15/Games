#pragma once

#include "../Common/Entity.hpp"

namespace Miner {
	class Entity : Common::Entity {
	public:
		Entity();
		virtual ~Entity();

		virtual void update(float _delta) = 0;
		virtual void updateTick(void) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;
	};
}