#include "ProjectileManager.hpp"

#include "Projectile.hpp"
#include "GameBoard.hpp"
#include "../Common/InstanceCollection.hpp"
#include "../Common/Application.hpp"

namespace SpaceInvaders {

	const std::string ProjectileManager::Name = "ProjectileManager";

	ProjectileManager::ProjectileManager() {}


	ProjectileManager::~ProjectileManager() {}

	void ProjectileManager::update(float _delta) {
		auto windowSize = sf::Vector2f(Common::InstanceCollection::getInstance<Common::Application>().getWindow().getSize());
		float minY = 0.0f;
		for (auto& p : m_Projectiles) {
			p->update(_delta);

			if (p->getBounds().top < minY) {
				p->kill();
			}
		}


		for (int i = static_cast<int>(m_Projectiles.size()) - 1; i >= 0; i -= 1) {
			if (!m_Projectiles[i]->isAlive()) {
				delete m_Projectiles[i];
				m_Projectiles.erase(m_Projectiles.begin() + i);
			}
		}

		for (auto& p : m_ProjectilesToAdd) {
			m_Projectiles.push_back(p);
		}
		m_ProjectilesToAdd.clear();

	}

	void ProjectileManager::handleEvent(sf::Event _event) {
		for (auto& p : m_Projectiles) {
			p->handleEvent(_event);
		}
	}

	void ProjectileManager::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		for (auto& p : m_Projectiles) {
			_target.draw(*p, _states);
		}
	}

	void ProjectileManager::addProjectile(Projectile *_p) {
		m_ProjectilesToAdd.push_back(_p);
	}

	Projectile *ProjectileManager::getCollidingProjectile(const sf::FloatRect& _bounds) {

		for (auto& p : m_Projectiles) {
			if (p->isAlive() && p->getBounds().intersects(_bounds)) {
				return p;
			}
		}

		return nullptr;
	}
}