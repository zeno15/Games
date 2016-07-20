#pragma once

#include "../Common/Entity.hpp"

#include "Player.hpp"
#include "AlienHorde.hpp"

#include <vector>

namespace SpaceInvaders {

	class GameBoard : public Common::Entity {
	public:
		GameBoard();
		~GameBoard();

		static const float GameHeight;
		static const float GameWidth;
		static const float GameBorderSize;

		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	private:
		AlienHorde m_Horde;

		sf::RectangleShape m_Bounds;

		Player *m_Player;
	};

}