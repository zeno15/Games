#pragma once 

#include "Region.hpp"
#include "../Common/Scene.hpp"

namespace Miner {
	class GameScene : public Common::Scene {
	public:
		GameScene(void);
		~GameScene(void);

		// Inherited via Scene
		virtual void update(float _delta) override;
		virtual void handleEvent(const sf::Event & _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	private:
		Region m_Region;
	};
}