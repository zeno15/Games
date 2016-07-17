#pragma once

#include "Cell.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace MineSweeper {

	class GameBoard : public sf::Drawable {
	public:
		GameBoard(unsigned int _width, unsigned int _height, int _mines);
		~GameBoard();

		void update(float _delta);
		void handleEvent(sf::Event _event);
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;

		unsigned int getElapsedSeconds(void) const;
		unsigned int getWidth(void) const;
		unsigned int getHeight(void) const;
		int getTotalMines(void) const;

		int getNumberOfMinesNextTo(unsigned int _x, unsigned int _y) const;

	private:
		void markMine(void);
		void unMarkMine(void);

		void revealCell(Cell *_cell);

		void revealAllMines(void);
		void flagAllMines(void);

		void handlePotentialWin(void);

		std::vector<Cell *> getNeighbours(Cell *_cell);

	private:
		float m_ElapsedTime;

		unsigned int m_Width;
		unsigned int m_Height;
		unsigned int m_UnrevealedCells;
		int m_TotalMines;
		int m_MarkedMines;

		std::vector<Cell> m_Cells;

		bool m_PlayerHasLost;
	};

}