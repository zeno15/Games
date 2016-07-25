#pragma once

#include "../Common/Entity.hpp"

namespace Survival {
	class Entity : Common::Entity {
	public:
		Entity(bool _holdsPressure, bool _isGhost);
		virtual ~Entity();

		virtual void update(float _delta) = 0;
		virtual void updateTick(void) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;

		bool holdsPressure(void) const;
		bool isGhost(void) const;
		void changeAlpha(float _alpha);
		virtual void handleAlphaChange(void);

	protected:
		bool m_HoldsPressure;
		bool m_IsGhost;
		float m_Alpha;
	};
}