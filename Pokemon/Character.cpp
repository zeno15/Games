#include "Character.hpp"

#include "../Common/VectorMath.hpp"
#include "../Common/InstanceCollection.hpp"
#include "RegionManager.hpp"
#include "Region.hpp"

#include <iostream>

#define SPEED 4.0f

namespace Pokemon {

	Character::Character() {}


	Character::~Character() {}

	void Character::update(float _delta) {
		if (m_Position != m_TargetPosition) {
			// move closer to target position
			auto distance = Common::VectorMath::distance(m_Position, m_TargetPosition);
			auto movement = SPEED * _delta;
			if (distance < movement) {
				m_Position = m_TargetPosition;
				auto& region = Common::InstanceCollection::getInstance<RegionManager>();

				region.getCurrentRegion()->getTile(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y)).onEntityEntered(this);
			}
			else {
				m_Position += Common::Orientation::directionToVector(m_Direction) * movement;
			}
		}
	}


	void Character::handleEvent(sf::Event _event) {	}

	void Character::face(Common::Orientation::Direction _direction) {
		m_Direction = _direction;
	}
	void Character::move(Common::Orientation::Direction _direction) {
		auto& region = Common::InstanceCollection::getInstance<RegionManager>();

		if (m_Direction == _direction) {
			// Already facing, so start moving
			m_TargetPosition += Common::Orientation::directionToVector(_direction);
			if (region.getCurrentRegion()->canMoveTo(static_cast<int>(m_TargetPosition.x), static_cast<int>(m_TargetPosition.y))) {
				region.getCurrentRegion()->getTile(static_cast<unsigned int>(m_Position.x), static_cast<unsigned int>(m_Position.y)).free();
				region.getCurrentRegion()->getTile(static_cast<unsigned int>(m_TargetPosition.x), static_cast<unsigned int>(m_TargetPosition.y)).reserve();
				region.getCurrentRegion()->getTile(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y)).onEntityLeave(this);
			}
			else {
				m_TargetPosition = m_Position;
			}
		}
		else {
			// Not facing, so turn to face
			face(_direction);
			region.getCurrentRegion()->getTile(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y)).onEntityMovedWithin(this);
		}
	}
}