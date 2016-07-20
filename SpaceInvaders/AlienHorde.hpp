#pragma once

#include "BasicAlien.hpp"

#include "../Common/Entity.hpp"

#include <vector>

namespace SpaceInvaders {

	class AlienHorde : public Common::Entity {
	public:
		AlienHorde(unsigned int _rows, unsigned int _columns);
		~AlienHorde();

		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		enum MovementState {
			Right,
			RightDown,
			Left,
			LeftDown
		};


	private:
		static const sf::Vector2f StartPositionOffset;

		void generateAliens(unsigned int _rows, unsigned int _columns);

		sf::FloatRect getBoundsForAlien(unsigned int _x, unsigned int _y) const;
		sf::FloatRect getHordeBounds(void) const;

	private:
		unsigned int m_StartingRows;
		unsigned int m_StartingColumns;

		float desiredDownwardMovement;
				
		std::vector<BasicAlien *> m_Aliens;

		sf::Vector2f m_HordeOffset;
		sf::Vector2u m_HordeChangeOffset;
		sf::Vector2u m_HordeChangeSize;

		MovementState m_MovementState;
	};

}