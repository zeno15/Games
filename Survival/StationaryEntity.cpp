#include "StationaryEntity.hpp"


namespace Survival {

	StationaryEntity::StationaryEntity(bool _holdsPressure, bool _isGhost) :
	Entity(_holdsPressure, _isGhost) {}


	StationaryEntity::~StationaryEntity() {}

}