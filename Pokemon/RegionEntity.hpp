#pragma once

#include "../Common/Entity.hpp"

namespace Pokemon {

	class RegionEntity : public Common::Entity {
	public:
		RegionEntity(bool _canJumpRegions);
		~RegionEntity();

		virtual void update(float _delta) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const = 0;

		bool canJumpRegions(void) const;

		void setPosition(const sf::Vector2f& _position);

	protected:
		sf::Vector2f m_Position;
		sf::Vector2f m_TargetPosition;
		bool m_CanJumpRegions;
	};

}