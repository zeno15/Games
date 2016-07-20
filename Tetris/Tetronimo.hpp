#pragma once

namespace Tetris {

	class Tetronimo {
	public:
		enum Type {
			Tetronimo_I,
			Tetronimo_J,
			Tetronimo_L,
			Tetronimo_O,
			Tetronimo_S,
			Tetronimo_T,
			Tetronimo_Z
		};

		Tetronimo(Type _type);
		~Tetronimo();

		Type getType(void) const;

	private:
		Type m_Type;
	};
}