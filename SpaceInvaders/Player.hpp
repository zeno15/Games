#pragma once

#include "../Common/Entity.hpp"

namespace SpaceInvaders {

	class Player : public Common::Entity {
	public:
		Player();
		~Player();

		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		static const float Width;
		static const float Height;

	private:
		sf::RectangleShape m_Basic;
		float m_HorizontalOffset;
	};

}