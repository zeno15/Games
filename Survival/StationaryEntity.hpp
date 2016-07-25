#pragma once

#include "Entity.hpp"

namespace Survival {

	class StationaryEntity : public Entity  {
	public:
		StationaryEntity(bool _holdsPressure, bool _isGhost);
		~StationaryEntity();

		virtual void update(float _delta) = 0;
		virtual void updateTick(void) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const = 0;
	};

}