#pragma once 

#include "../Common/Scene.hpp"

namespace Tetris {
	class GameScene : public Common::Scene {
	public:
		GameScene(void);
		~GameScene(void);

		// Inherited via Scene
		virtual void update(float _delta) override;
		virtual void handleEvent(const sf::Event & _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;
	};
}