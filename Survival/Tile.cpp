#include "Tile.hpp"

#include "Entity.hpp"

#include "NotificationManager.hpp"
#include "../Common/InstanceCollection.hpp"
#include "../Common/ColourUtility.hpp"

namespace Survival {

	const float Tile::Width = 32.0f;
	const float Tile::Height = 32.0f;

	Tile::Tile(unsigned int _x, unsigned int _y) :
	m_X(_x),
	m_Y(_y),
	m_HoldsPressure(false),
	m_Entity(nullptr) {
		float thicknesss = 1.0f;
		m_Graphics = sf::RectangleShape(sf::Vector2f(Width - thicknesss * 2, Height - thicknesss * 2));
		m_Graphics.setPosition(sf::Vector2f(m_X * Width, m_Y * Height));
		m_Graphics.setOutlineColor(sf::Color::Black);
		m_Graphics.setFillColor(sf::Color(56, 56, 56));
		m_Graphics.setOutlineThickness(thicknesss);
		m_Graphics.setOrigin(-thicknesss, -thicknesss);
	}


	Tile::~Tile() {

	}
	

	void Tile::update(float _delta) {
		if (hasEntity()) {
			m_Entity->update(_delta);
		}
	}
	void Tile::updateTick(void) {
		if (hasEntity()) {
			m_Entity->updateTick();
		}
	}
	void Tile::handleEvent(sf::Event _event) {
		if (hasEntity()) {
			m_Entity->handleEvent(_event);
		}
	}
	void Tile::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		_target.draw(m_Graphics, _states);
		if (hasEntity()) {
			_states.transform.translate(sf::Vector2f(Width * m_X, Height * m_Y) + sf::Vector2f(Width, Height) / 2.0f);
			m_Entity->draw(_target, _states);
		}
	}

	unsigned int Tile::getX(void) const {
		return m_X;
	}
	unsigned int Tile::getY(void) const {
		return m_Y;
	}
	
	Entity *Tile::getEntity(void) {
		return m_Entity;
	}
	void Tile::setEntity(Entity *_entity) {
		m_Entity = _entity;

		setHoldsPressure(false);
		if (m_Entity != nullptr) {
			setHoldsPressure(m_Entity->holdsPressure());
		}

		updated();
	}

	bool Tile::holdsPressure(void) const {
		return m_HoldsPressure;
	}
	void Tile::setHoldsPressure(bool _holdsPressure) {
		m_HoldsPressure = _holdsPressure;
	}

	bool Tile::hasEntity(void) const {
		return m_Entity != nullptr;
	}
	void Tile::updated(void) {
		auto& n = Common::InstanceCollection::getInstance<NotificationManager>();
		if (n.tileUpdated) {
			n.tileUpdated(m_X, m_Y);
		}
	}
}