#pragma once

#include "Character.hpp"

namespace Pokemon {

	class WanderingCharacter : public Character {
	public:
		WanderingCharacter();
		~WanderingCharacter();

		// Inherited via Character
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	private:
		void refreshWanderTime(float _min, float _max);

		void moveRandomDirection(void);

	private:
		float m_AccumulatedTime;
		float m_WanderTime;
	};

}