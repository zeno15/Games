#pragma once

#include "../Common/Entity.hpp"
#include "../Common/Manager.hpp"

#include <vector>

namespace Common {
	class InstanceCollection;
}

namespace SpaceInvaders {

	class Projectile;

	class ProjectileManager : public Common::Manager, public Common::Entity {
	public:
		friend class Common::InstanceCollection;

		const static std::string Name;

		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		void addProjectile(Projectile *_p);

		Projectile *getCollidingProjectile(const sf::FloatRect& _bounds);

	private:
		ProjectileManager();
		~ProjectileManager();

		std::vector<Projectile *> m_Projectiles;
		std::vector<Projectile *> m_ProjectilesToAdd;
	};

}