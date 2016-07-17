#pragma once

#include <string>

#include <SFML\Graphics.hpp>

namespace Common {

	class Scene : public sf::Drawable {
	public:
		Scene(const std::string& _name);
		~Scene();

		std::string getName(void) const;

		virtual void update(float _delta) = 0;
		virtual void handleEvent(const sf::Event& _event) = 0;
		virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const = 0;


	private:
		std::string m_Name;
	};

}