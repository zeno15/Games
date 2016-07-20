#include "Tetronimo.hpp"

namespace Tetris {

	Tetronimo::Tetronimo(Type _type) :
		m_Type(_type) {
	}


	Tetronimo::~Tetronimo() {
	}


	Tetronimo::Type Tetronimo::getType(void) const {
		return m_Type;
	}
}