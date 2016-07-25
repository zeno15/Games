#include "Entity.hpp"

namespace Survival {

	Entity::Entity(bool _holdsPressure, bool _isGhost) :
	m_HoldsPressure(_holdsPressure),
	m_IsGhost(_isGhost),
	m_Alpha(1.0f) {

	}
	Entity::~Entity() {

	}

	bool Entity::holdsPressure(void) const {
		return m_HoldsPressure;
	}
	bool Entity::isGhost(void) const {
		return m_IsGhost;
	}

	void Entity::changeAlpha(float _alpha) {
		m_Alpha = _alpha;
		handleAlphaChange();
	}
	void Entity::handleAlphaChange(void) {

	}
}