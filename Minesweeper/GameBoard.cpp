#include "GameBoard.hpp"

#include "NotificationManager.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <functional>

#include "../Common/InstanceCollection.hpp"

namespace MineSweeper {

	GameBoard::GameBoard(unsigned int _width, unsigned int _height, int _mines) :
		m_Width(_width),
		m_Height(_height),
		m_TotalMines(_mines),
		m_PlayerHasLost(false),
		m_MarkedMines(0),
		m_UnrevealedCells(_width * _height) {
		for (unsigned int i = 0; i < m_Height; i += 1) {
			for (unsigned int j = 0; j < m_Width; j += 1) {
				m_Cells.emplace_back(j, i, false);
			}
		}

		int placed = 0;
		while (placed != m_TotalMines) {
			unsigned int x = rand() % m_Width;
			unsigned int y = rand() % m_Height;

			if (!m_Cells[y * m_Width + x].isMine()) {
				m_Cells[y * m_Width + x].setAsMine();
				placed += 1;
			}
		}

		for (unsigned int i = 0; i < m_Height; i += 1) {
			for (unsigned int j = 0; j < m_Width; j += 1) {
				m_Cells[i * m_Width + j].setNumberOfNeighbouringMines(getNumberOfMinesNextTo(j, i));
			}
		}

		Common::InstanceCollection::getInstance<NotificationManager>().RevealCell = std::bind(&GameBoard::revealCell, this, std::placeholders::_1);
		Common::InstanceCollection::getInstance<NotificationManager>().MarkMine = std::bind(&GameBoard::markMine, this);
		Common::InstanceCollection::getInstance<NotificationManager>().UnMarkMine = std::bind(&GameBoard::unMarkMine, this);

		handlePotentialWin();
	}

	GameBoard::~GameBoard() {}


	void GameBoard::update(float _delta) {
		m_ElapsedTime += _delta;
	}
	void GameBoard::handleEvent(sf::Event _event) {
		if (!m_PlayerHasLost) {
			for (auto& c : m_Cells) {
				c.handleEvent(_event);
			}
		}
	}
	void GameBoard::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
		for (auto& c : m_Cells) {
			_target.draw(c, _states);
		}
	}

	unsigned int GameBoard::getElapsedSeconds(void) const {
		return static_cast<unsigned int>(std::floorf(m_ElapsedTime));
	}
	unsigned int GameBoard::getWidth(void) const {
		return m_Width;
	}
	unsigned int GameBoard::getHeight(void) const {
		return m_Height;
	}
	int GameBoard::getTotalMines(void) const {
		return m_TotalMines;
	}
	int GameBoard::getNumberOfMinesNextTo(unsigned int _x, unsigned int _y) const {
		int mines = 0;

		// TL
		if (_x > 0 && _y > 0) {
			mines += m_Cells[(_y - 1) * m_Width + (_x - 1)].isMine() ? 1 : 0;
		}
		// T
		if (_y > 0) {
			mines += m_Cells[(_y - 1) * m_Width + (_x + 0)].isMine() ? 1 : 0;
		}
		// TR
		if (_x < m_Width - 1 && _y > 0) {
			mines += m_Cells[(_y - 1) * m_Width + (_x + 1)].isMine() ? 1 : 0;
		}

		// L
		if (_x > 0) {
			mines += m_Cells[(_y + 0) * m_Width + (_x - 1)].isMine() ? 1 : 0;
		}
		// R
		if (_x < m_Width - 1) {
			mines += m_Cells[(_y + 0) * m_Width + (_x + 1)].isMine() ? 1 : 0;
		}

		// BL
		if (_x > 0 && _y < m_Height - 1) {
			mines += m_Cells[(_y + 1) * m_Width + (_x - 1)].isMine() ? 1 : 0;
		}
		// B
		if (_y < m_Height - 1) {
			mines += m_Cells[(_y + 1) * m_Width + (_x + 0)].isMine() ? 1 : 0;
		}
		// BR
		if (_x < m_Width - 1 && _y < m_Height - 1) {
			mines += m_Cells[(_y + 1) * m_Width + (_x + 1)].isMine() ? 1 : 0;
		}

		return mines;
	}

	void GameBoard::revealCell(Cell *_cell) {
		if (!_cell->isRevealed() && !_cell->isMine()) {
			m_UnrevealedCells -= 1;
		}
		_cell->reveal();

		if (_cell->isMine()) {
			if (!m_PlayerHasLost) {
				revealAllMines();
				m_PlayerHasLost = true;
				Common::InstanceCollection::getInstance<NotificationManager>().NotifyLoss();
			}
			return;
		}

		if (_cell->getNeighbouringMines() == 0) {
			auto& neighbours = getNeighbours(_cell);

			for (auto& n : neighbours) {
				if (!n->isRevealed()) {
					revealCell(n);
				}
			}
		}
		handlePotentialWin();
	}
	std::vector<Cell *> GameBoard::getNeighbours(Cell *_cell) {
		std::vector<Cell *> cells;

		unsigned int _x = _cell->getX();
		unsigned int _y = _cell->getY();

		// TL
		if (_x > 0 && _y > 0) {
			cells.push_back(&m_Cells[(_y - 1) * m_Width + (_x - 1)]);
		}
		// T
		if (_y > 0) {
			cells.push_back(&m_Cells[(_y - 1) * m_Width + (_x + 0)]);
		}
		// TR
		if (_x < m_Width - 1 && _y > 0) {
			cells.push_back(&m_Cells[(_y - 1) * m_Width + (_x + 1)]);
		}

		// L
		if (_x > 0) {
			cells.push_back(&m_Cells[(_y + 0) * m_Width + (_x - 1)]);
		}
		// R
		if (_x < m_Width - 1) {
			cells.push_back(&m_Cells[(_y + 0) * m_Width + (_x + 1)]);
		}

		// BL
		if (_x > 0 && _y < m_Height - 1) {
			cells.push_back(&m_Cells[(_y + 1) * m_Width + (_x - 1)]);
		}
		// B
		if (_y < m_Height - 1) {
			cells.push_back(&m_Cells[(_y + 1) * m_Width + (_x + 0)]);
		}
		// BR
		if (_x < m_Width - 1 && _y < m_Height - 1) {
			cells.push_back(&m_Cells[(_y + 1) * m_Width + (_x + 1)]);
		}

		return cells;
	}
	void GameBoard::revealAllMines(void) {
		for (auto& c : m_Cells) {
			if (c.isMine()) {
				c.reveal();
			}
		}
	}
	void GameBoard::flagAllMines(void) {
		for (auto& c : m_Cells) {
			if (c.isMine()) {
				c.setState(Cell::State::Mine);
			}
		}
	}
	void GameBoard::markMine(void) {
		m_MarkedMines += 1;
	}
	void GameBoard::unMarkMine(void) {
		m_MarkedMines -= 1;
	}
	void GameBoard::handlePotentialWin(void) {
		if (m_TotalMines == m_UnrevealedCells) {
			flagAllMines();
			Common::InstanceCollection::getInstance<NotificationManager>().NotifyWin();
		}
	}

}