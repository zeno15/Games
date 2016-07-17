#pragma once

#include <SFML/Graphics.hpp>
#include "../Common/InstanceCollection.hpp"
#include "CellSprites.hpp"

namespace MineSweeper {

#define CELL_SIZE 24.0f
#define OUTLINE_SIZE 1.0f

	class Cell : public sf::Drawable {
	public:
		enum State {
			Revealed,
			Unrevealed,
			Mine,
			Unkown
		};

		Cell(unsigned int _x, unsigned int _y, bool _isMine);
		~Cell();

		void handleEvent(sf::Event _event);
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;

		unsigned int getX(void) const;
		unsigned int getY(void) const;

		void setAsMine(void);
		bool isMine(void) const;

		void setNumberOfNeighbouringMines(int _number);

		int getNeighbouringMines(void) const;

		CellSprites::Sprite getSpriteType(void) const;
		bool isRevealed(void) const;

		void reveal(void);

		void setState(State _state);

	private:
		void progressStateOnLeftClick(void);
		void progressStateOnRightClick(void);

		void handleRevealingCell(void);

	private:
		unsigned int m_XCoordinate;
		unsigned int m_YCoordinate;
		bool m_IsMine;

		int m_NumberOfNeighbouringMines;

		sf::RectangleShape m_Cell;

		State m_State;
	};

}