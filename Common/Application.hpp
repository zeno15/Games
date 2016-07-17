#pragma once

#include <SFML\Graphics.hpp>

#include "Manager.hpp"

namespace Common {

	class Application : public Manager {
	public:
		friend class InstanceCollection;

		const static std::string Name;

		void initialise(const sf::Vector2u& _size, const std::string& _title);

		void start(void);

		void stop(void);

		sf::RenderWindow& getWindow(void);

		bool isRunning(void) const;

	private:
		Application();
		~Application();

		void update(float _delta);
		void render(float _alpha);

		bool m_Running;

		sf::RenderWindow m_Window;
	};

}