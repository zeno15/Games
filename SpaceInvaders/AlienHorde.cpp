#include "AlienHorde.hpp"

#include "GameBoard.hpp"
#include "Projectile.hpp"
#include "ProjectileManager.hpp"
#include "../Common/InstanceCollection.hpp"
#include "NotificationManager.hpp"

#include <iostream>

#define SPEED 128.0f

namespace SpaceInvaders {

	const sf::Vector2f AlienHorde::StartPositionOffset = sf::Vector2f(BasicAlien::BoundingWidth / 2.0f, BasicAlien::BoundingHeight / 2.0f);

	AlienHorde::AlienHorde(unsigned int _rows, unsigned int _columns) :
	m_StartingRows(_rows),
	m_StartingColumns(_columns),
	m_MovementState(MovementState::Right){
		generateAliens(_rows, _columns);
	}


	AlienHorde::~AlienHorde() {}

	void AlienHorde::update(float _delta) {

		auto bottom = getHordeBounds().top + getHordeBounds().height + m_HordeOffset.y;
		if (bottom >= GameBoard::GameHeight) {
			Common::InstanceCollection::getInstance<NotificationManager>().NotifyPlayerLost();
			return;
		}

		if (m_MovementState == MovementState::Right) {
			m_HordeOffset.x += SPEED * _delta;
			
			auto maxHordeOffset = GameBoard::GameWidth - getHordeBounds().width - getHordeBounds().left;

			if (m_HordeOffset.x >= maxHordeOffset) {
				m_HordeOffset.x = maxHordeOffset;
				m_MovementState = MovementState::RightDown;
				desiredDownwardMovement = BasicAlien::BoundingHeight;
			}
		}
		else if (m_MovementState == MovementState::RightDown) {
			m_HordeOffset.y += SPEED * _delta;
			desiredDownwardMovement -= SPEED * _delta;

			if (desiredDownwardMovement <= 0.0f) {
				m_MovementState = MovementState::Left;
				m_HordeOffset.y += desiredDownwardMovement;
			}
		}
		else if (m_MovementState == Left) {
			m_HordeOffset.x -= SPEED * _delta;

			float offset = m_HordeOffset.x + getHordeBounds().left;
  			if (offset <= 0.0f) {
				m_HordeOffset.x -= offset;
				m_MovementState = MovementState::LeftDown;
				desiredDownwardMovement = BasicAlien::BoundingHeight;
			}
		}
		else if (m_MovementState == MovementState::LeftDown) {
			m_HordeOffset.y += SPEED * _delta;
			desiredDownwardMovement -= SPEED * _delta;

			if (desiredDownwardMovement <= 0.0f) {
				m_MovementState = MovementState::Right;
				m_HordeOffset.y += desiredDownwardMovement;
			}
		}

		bool boundsNeedUpdating = false;

		auto& projectileManager = Common::InstanceCollection::getInstance<ProjectileManager>();
		
		for (unsigned int y = 0; y < m_StartingRows; y += 1) {
			for (unsigned int x = 0; x < m_StartingColumns; x += 1) {
				if (m_Aliens[y * m_StartingColumns + x]->isAlive()) {
					auto a = m_Aliens[y * m_StartingColumns + x];
					auto p = projectileManager.getCollidingProjectile(getBoundsForAlien(x, y));
					if (p != nullptr) {
						a->kill();
						p->kill();
						boundsNeedUpdating = true;
						continue;
					}
				}
			}
		}

		if (boundsNeedUpdating) {
			bool anyAlive = false;

			unsigned int left = m_StartingColumns - 1;
			unsigned int right = 0;
			unsigned int top = m_StartingRows - 1;
			unsigned int bottom = 0;
			for (unsigned int y = 0; y < m_StartingRows; y += 1) {
				for (unsigned int x = 0; x < m_StartingColumns; x += 1) {
					if (m_Aliens[y * m_StartingColumns + x]->isAlive()) {
						anyAlive = true;

						if (left > x) {
							left = x;
						}
						if (right < x) {
							right = x;
						}
						if (top > y) {
							top = y;
						}
						if (bottom < y) {
							bottom = y;
						}
					}
				}
			}

			if (!anyAlive) {
				Common::InstanceCollection::getInstance<NotificationManager>().NotifyPlayerWon();
				return;
			}

			m_HordeChangeOffset = sf::Vector2u(left, top);

			m_HordeChangeSize.x = m_StartingColumns - (1 + right - left);
			m_HordeChangeSize.y = m_StartingRows - (1 + bottom - top);
		}
	}

	void AlienHorde::handleEvent(sf::Event _event) {}

	void AlienHorde::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		auto boundsStates = _states;

		auto hordeBounds = getHordeBounds();
		boundsStates.transform.translate(m_HordeOffset + sf::Vector2f(hordeBounds.left, hordeBounds.top));

		sf::RectangleShape b = sf::RectangleShape(sf::Vector2f(hordeBounds.width, hordeBounds.height));
		b.setFillColor(sf::Color::Transparent);
		b.setOutlineColor(sf::Color::Black);
		b.setOutlineThickness(1.0f);

		_target.draw(b, boundsStates);


		_states.transform.translate(StartPositionOffset + m_HordeOffset);

		for (unsigned int y = 0; y < m_StartingRows; y += 1) {
			for (unsigned int x = 0; x < m_StartingColumns; x += 1) {
				if (m_Aliens[y * m_StartingColumns + x]->isAlive()) {
					_target.draw(*m_Aliens[y * m_StartingColumns + x], _states);
				}				
				_states.transform.translate(sf::Vector2f(BasicAlien::BoundingWidth + BasicAlien::SpacingWidth, 0.0f));
			}
			_states.transform.translate(sf::Vector2f(0.0f, BasicAlien::BoundingHeight + BasicAlien::SpacingHeight));
			_states.transform.translate(-sf::Vector2f((BasicAlien::BoundingWidth + BasicAlien::SpacingWidth) * m_StartingColumns, 0.0f));
		}

	}

	sf::FloatRect AlienHorde::getBoundsForAlien(unsigned int _x, unsigned int _y) const {
		return sf::FloatRect(
			m_HordeOffset.x + StartPositionOffset.x + (BasicAlien::BoundingWidth + BasicAlien::SpacingWidth) * _x - BasicAlien::BoundingWidth / 2.0f,
			m_HordeOffset.y + StartPositionOffset.y + (BasicAlien::BoundingHeight + BasicAlien::SpacingHeight) * _y - BasicAlien::BoundingHeight / 2.0f,
			BasicAlien::BoundingWidth,
			BasicAlien::BoundingHeight);
	}
	sf::FloatRect AlienHorde::getHordeBounds(void) const {
		return sf::FloatRect(
			(BasicAlien::BoundingWidth + BasicAlien::SpacingWidth) * m_HordeChangeOffset.x,
			(BasicAlien::BoundingHeight + BasicAlien::SpacingHeight) * m_HordeChangeOffset.y,
			(BasicAlien::BoundingWidth + BasicAlien::SpacingWidth) * (m_StartingColumns - m_HordeChangeSize.x) - BasicAlien::SpacingWidth,
			(BasicAlien::BoundingHeight + BasicAlien::SpacingHeight) * (m_StartingRows - m_HordeChangeSize.y) - BasicAlien::SpacingHeight);
	}


	void AlienHorde::generateAliens(unsigned int _rows, unsigned int _columns) {
		for (unsigned int y = 0; y < _rows; y += 1) {
			for (unsigned int x = 0; x < _columns; x += 1) {
				if (y == 0) {
					m_Aliens.push_back(new BasicAlien(BasicAlien::AlienType::Large));
				}
				else if (y == 1) {
					m_Aliens.push_back(new BasicAlien(BasicAlien::AlienType::Medium));
				}
				else {
					m_Aliens.push_back(new BasicAlien(BasicAlien::AlienType::Small));
				}
			
			}
		}
	}
}