#include "Projectile.hpp"

#define WIDTH 4.0f
#define HEIGHT 8.0f

namespace SpaceInvaders {

	Projectile::Projectile(const sf::Vector2f& _position, const sf::Vector2f& _direction, float _speed) :
		m_Position(_position),
		m_Direction(_direction),
		m_Speed(_speed),
		m_Alive(true) {

		m_Position.x -= WIDTH / 2.0f;
	}


	Projectile::~Projectile() {}

	void Projectile::update(float _delta) {
		m_Position += m_Direction * m_Speed * _delta;
	}

	void Projectile::handleEvent(sf::Event _event) {}

	void Projectile::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::RectangleShape r;
		r.setFillColor(sf::Color::Magenta);
		r.setSize(sf::Vector2f(getBounds().width, getBounds().height));
		r.setPosition(getBounds().left, getBounds().top);
		_target.draw(r, _states);
	}

	sf::FloatRect Projectile::getBounds(void) const {
		return sf::FloatRect(m_Position.x, m_Position.y, WIDTH, HEIGHT);
	}

	bool Projectile::isAlive(void) const {
		return m_Alive;
	}
	void Projectile::kill(void) {
		m_Alive = false;
	}
	sf::Vector2f Projectile::getPosition(void) const {
		return m_Position;
	}
}