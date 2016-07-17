#include "Cell.hpp"

#include "NotificationManager.hpp"

#include <iostream>

namespace MineSweeper {

	Cell::Cell(unsigned int _x, unsigned int _y, bool _isMine) :
		m_XCoordinate(_x),
		m_YCoordinate(_y),
		m_IsMine(_isMine),
		m_State(State::Unrevealed) {
		m_Cell = sf::RectangleShape(sf::Vector2f(CELL_SIZE - 2 * OUTLINE_SIZE, CELL_SIZE - 2 * OUTLINE_SIZE));
		m_Cell.setPosition(_x * CELL_SIZE + OUTLINE_SIZE, _y * CELL_SIZE + OUTLINE_SIZE);
		m_Cell.setFillColor(m_IsMine ? sf::Color::Red : sf::Color::Green);
		m_Cell.setOutlineColor(sf::Color::Blue);
		m_Cell.setOutlineThickness(OUTLINE_SIZE);
	}

	Cell::~Cell() {}

	void Cell::handleEvent(sf::Event _event) {
		if (_event.type == sf::Event::MouseButtonReleased) {
			sf::Vector2f mousePosition = sf::Vector2f(static_cast<float>(_event.mouseButton.x), static_cast<float>(_event.mouseButton.y));

			sf::FloatRect bounds = sf::FloatRect(m_XCoordinate * CELL_SIZE + OUTLINE_SIZE, m_YCoordinate * CELL_SIZE + OUTLINE_SIZE, CELL_SIZE, CELL_SIZE);

			if (bounds.contains(mousePosition)) {
				if (_event.mouseButton.button == sf::Mouse::Left) {
					std::cout << "Left button pressed for cell x: " << m_XCoordinate << ", y: " << m_YCoordinate << ", number: " << m_NumberOfNeighbouringMines << std::endl;
					progressStateOnLeftClick();
				}
				else if (_event.mouseButton.button == sf::Mouse::Right) {
					std::cout << "Right button pressed for cell x: " << m_XCoordinate << ", y: " << m_YCoordinate << ", number: " << m_NumberOfNeighbouringMines << std::endl;
					progressStateOnRightClick();
				}
			}
		}
	}
	void Cell::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
		Common::InstanceCollection::getInstance<CellSprites>().renderSprite(_target, getSpriteType(), m_XCoordinate, m_YCoordinate);
	}

	unsigned int Cell::getX(void) const {
		return m_XCoordinate;
	}
	unsigned int Cell::getY(void) const {
		return m_YCoordinate;
	}

	bool Cell::isMine(void) const {
		return m_IsMine;
	}
	void Cell::setNumberOfNeighbouringMines(int _number) {
		m_NumberOfNeighbouringMines = _number;
	}
	int Cell::getNeighbouringMines(void) const {
		return m_NumberOfNeighbouringMines;
	}
	void Cell::progressStateOnLeftClick(void) {
		handleRevealingCell();
	}
	void Cell::progressStateOnRightClick(void) {
		if (m_State == State::Revealed) {
			return;
		}

		switch (m_State) {
		case State::Unrevealed:
			Common::InstanceCollection::getInstance<NotificationManager>().MarkMine();
			m_State = State::Mine;
			break;
		case State::Mine:
			Common::InstanceCollection::getInstance<NotificationManager>().UnMarkMine();
			m_State = State::Unkown;
			break;
		case State::Unkown:
			m_State = State::Unrevealed;
			break;
		}


	}
	void Cell::handleRevealingCell(void) {
		Common::InstanceCollection::getInstance<NotificationManager>().RevealCell(this);
	}
	CellSprites::Sprite Cell::getSpriteType(void) const {


		switch (m_State) {
		case State::Unrevealed:
			return CellSprites::Sprite::Starting;
		case State::Unkown:
			return CellSprites::Sprite::Unknown;
		case State::Mine:
			return CellSprites::Sprite::MineFlag;
		case State::Revealed:
			if (isMine()) {
				return CellSprites::Sprite::Mine;
			}
			return static_cast<CellSprites::Sprite>(CellSprites::Sprite::Mines_0 + m_NumberOfNeighbouringMines);
			break;
		}




		return CellSprites::Sprite::Mines_9;
	}
	void Cell::reveal(void) {
		if (m_State == State::Revealed) {
			return;
		}
		if (m_State == State::Mine) {
			Common::InstanceCollection::getInstance<NotificationManager>().UnMarkMine();
		}
		m_State = State::Revealed;
	}
	bool Cell::isRevealed(void) const {
		return m_State == State::Revealed;
	}
	void Cell::setAsMine(void) {
		m_IsMine = true;
	}
	void Cell::setState(State _state) {
		if (_state != m_State) {
			m_State = _state;
			if (m_State == State::Mine) {
				Common::InstanceCollection::getInstance<NotificationManager>().MarkMine();
			}
		}
	}

}