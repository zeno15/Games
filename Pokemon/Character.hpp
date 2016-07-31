#pragma once

#include "RegionEntity.hpp"
#include "../Common/Orientation.hpp"

namespace Pokemon {

	class Character : public RegionEntity {
	public:
		Character(bool _canJumpRegions);
		~Character();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const = 0;

		void face(Common::Orientation::Direction _direction);
		void move(Common::Orientation::Direction _direction);

	protected:
		Common::Orientation::Direction m_Direction;
	};

}