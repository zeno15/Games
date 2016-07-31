#include "RegionEntity.hpp"

namespace Pokemon {

	RegionEntity::RegionEntity(bool _canJumpRegions) :
	m_CanJumpRegions(_canJumpRegions) {}

	RegionEntity::~RegionEntity() {}


	bool RegionEntity::canJumpRegions(void) const {
		return m_CanJumpRegions;
	}
	void RegionEntity::setPosition(const sf::Vector2f& _position) {
		m_Position = _position;
		m_TargetPosition = _position;
	}
}