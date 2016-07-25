#include "Player.hpp"

#include "Tile.hpp"

#include "../Common/VectorMath.hpp"
#include "../Common/InstanceCollection.hpp"
#include "NotificationManager.hpp"
#include "LevelManager.hpp"
#include "Level.hpp"
#include "EntityGhost.hpp"

#include <iostream>

#define SPEED 4.0f

namespace Survival {

	Player::Player() :
	m_Direction(Common::Orientation::Direction::South) {}


	Player::~Player() {}

	void Player::update(float _delta) {
		if (m_Position != m_TargetPosition) {
			// move closer to target position
			auto distance = Common::VectorMath::distance(m_Position, m_TargetPosition);
			auto movement = SPEED * _delta;
			if (distance < movement) {
				m_Position = m_TargetPosition;
			}
			else {
				m_Position += Common::Orientation::directionToVector(m_Direction) * movement;
			}
		}
	}

	void Player::updateTick(void) {}

	void Player::handleEvent(sf::Event _event) {
		auto& level = Common::InstanceCollection::getInstance<LevelManager>();
		if (_event.type == sf::Event::KeyPressed) {
			if (m_Position == m_TargetPosition) {
				if (_event.key.code == sf::Keyboard::Space) {
					auto interactPosition = m_Position + Common::Orientation::directionToVector(m_Direction);
					auto entity = level.getCurrentLevel()->getTileEntityAt(static_cast<int>(interactPosition.x), static_cast<int>(interactPosition.y));
					if (entity != nullptr) {
						if (entity->isGhost()) {
							auto ghost = dynamic_cast<EntityGhost *>(entity);
							if (ghost->getNeededResources().allResourcesExceptWorkCapped()) {
								ghost->getNeededResources().addResourceAmount(ResourceCollection::Resource::WorkName, 1);
							}
							if (ghost->getNeededResources().allResourcesCapped()) {
								Common::InstanceCollection::getInstance<NotificationManager>().ghostBuiltAt(static_cast<unsigned int>(interactPosition.x), static_cast<unsigned int>(interactPosition.y));
							}
						}
					}
				}
				else if (_event.key.code == sf::Keyboard::Left || _event.key.code == sf::Keyboard::A) {
					if (m_Direction == Common::Orientation::Direction::West) {
						// Already facing, so start moving
						m_TargetPosition += Common::Orientation::directionToVector(Common::Orientation::Direction::West);
						if (!level.getCurrentLevel()->canMoveToTileAt(static_cast<int>(m_TargetPosition.x), static_cast<int>(m_TargetPosition.y))) {
							m_TargetPosition = m_Position;
						}
					}
					else {
						// Not facing, so turn to face
						m_Direction = Common::Orientation::Direction::West;
					}
				}
				else if (_event.key.code == sf::Keyboard::Right || _event.key.code == sf::Keyboard::D) {
					if (m_Direction == Common::Orientation::Direction::East) {
						// Already facing, so start moving
						m_TargetPosition += Common::Orientation::directionToVector(Common::Orientation::Direction::East);
						if (!level.getCurrentLevel()->canMoveToTileAt(static_cast<int>(m_TargetPosition.x), static_cast<int>(m_TargetPosition.y))) {
							m_TargetPosition = m_Position;
						}
					}
					else {
						// Not facing, so turn to face
						m_Direction = Common::Orientation::Direction::East;
					}
				}
				else if (_event.key.code == sf::Keyboard::Up || _event.key.code == sf::Keyboard::W) {
					if (m_Direction == Common::Orientation::Direction::North) {
						// Already facing, so start moving
						m_TargetPosition += Common::Orientation::directionToVector(Common::Orientation::Direction::North);
						if (!level.getCurrentLevel()->canMoveToTileAt(static_cast<int>(m_TargetPosition.x), static_cast<int>(m_TargetPosition.y))) {
							m_TargetPosition = m_Position;
						}
					}
					else {
						// Not facing, so turn to face
						m_Direction = Common::Orientation::Direction::North;
					}
				}
				else if (_event.key.code == sf::Keyboard::Down || _event.key.code == sf::Keyboard::S) {
					if (m_Direction == Common::Orientation::Direction::South) {
						// Already facing, so start moving
						m_TargetPosition += Common::Orientation::directionToVector(Common::Orientation::Direction::South);
						if (!level.getCurrentLevel()->canMoveToTileAt(static_cast<int>(m_TargetPosition.x), static_cast<int>(m_TargetPosition.y))) {
							m_TargetPosition = m_Position;
						}
					}
					else {
						// Not facing, so turn to face
						m_Direction = Common::Orientation::Direction::South;
					}
				}
			}
		}
	}

	void Player::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		float rad = Tile::Width * 3.0f / 4.0f / 2.0f;
		sf::CircleShape c(rad);
		c.setOrigin(rad, rad);
		c.setPosition(sf::Vector2f(Tile::Width * m_Position.x, Tile::Height * m_Position.y) + sf::Vector2f(Tile::Width, Tile::Height) / 2.0f);
		_target.draw(c, _states);

		sf::CircleShape facing(4.0f);
		facing.setOrigin(4.0f, 4.0f);
		facing.setFillColor(sf::Color::Green);
		facing.setPosition(c.getPosition() + Common::Orientation::directionToVector(m_Direction) * rad);
		_target.draw(facing, _states);
	}
}