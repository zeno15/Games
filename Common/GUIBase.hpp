#pragma once

#include <SFML/Graphics.hpp>

namespace Common {

	class GUIBase {
	public:
		GUIBase();
		~GUIBase();

		virtual void update(float _delta);
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;
	};

}