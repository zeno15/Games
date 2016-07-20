#pragma once

#include "../Common/Entity.hpp"

namespace SpaceInvaders {

	class BasicAlien : public Common::Entity {
	public:
		enum AlienType {
			Small,
			Medium,
			Large
		};

		BasicAlien(AlienType _type);
		~BasicAlien();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const override;

		static const float BoundingWidth;
		static const float BoundingHeight;
		static const float SpacingWidth;
		static const float SpacingHeight;

		bool isAlive(void) const;

		void kill(void);

		AlienType getType(void) const;

	private:
		bool m_Alive;

		AlienType m_Type;
	};

}