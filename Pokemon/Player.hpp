#pragma once

#include "Character.hpp"

namespace Pokemon {

	class Player : public Character {
	public:
		Player();
		~Player();

		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;
	};

}