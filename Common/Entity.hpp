#pragma once

#include <SFML/Graphics.hpp>

namespace Common {
	class Entity : public sf::Drawable {

		virtual void update(float _delta) = 0;
		virtual void handleEvent(sf::Event _event) = 0;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;
	};
}