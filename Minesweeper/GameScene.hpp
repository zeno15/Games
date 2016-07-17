#pragma once

#include "GameBoard.hpp"
#include "../Common/Scene.hpp"
#include <SFML/Graphics.hpp>

namespace MineSweeper {
	class GameScene : public Common::Scene {
	public:
		GameScene();
		~GameScene();

		// Inherited via Scene
		virtual void update(float _delta) override;
		virtual void handleEvent(const sf::Event & _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		void reset(unsigned int _width, unsigned int _height, int _mines);

		void onWin(void);
		void onLoss(void);

		GameBoard *m_Board;

		sf::Text m_LostMessage;
		sf::Text m_WonMessage;

		enum State {
			Playing,
			Lost,
			Won
		} m_State;
	};

}