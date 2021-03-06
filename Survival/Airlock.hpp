#pragma once

#include "StationaryEntity.hpp"

namespace Survival {

	class Airlock : public StationaryEntity {
	public:
		Airlock();
		~Airlock();

		// Inherited via StationaryEntity
		virtual void update(float _delta) override;
		virtual void updateTick(void) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;
	};

}