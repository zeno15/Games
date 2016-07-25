#pragma once

#include "Level.hpp"
#include "../Common/Scene.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace Survival {

	class GameScene : public Common::Scene {
	public:
		GameScene();
		~GameScene();

		// Inherited via Scene
		virtual void update(float _delta) override;
		virtual void handleEvent(const sf::Event & _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		Level m_Level;
	};

}