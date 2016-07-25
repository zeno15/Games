#pragma once

#include "Entity.hpp"

namespace Miner {

	class Tile;
	class Miner : public Entity {
	public:
		Miner();
		~Miner();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void updateTick(void) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	private:
	};

}