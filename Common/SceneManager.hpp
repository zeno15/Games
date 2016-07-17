#pragma once

#include "Scene.hpp"
#include "Manager.hpp"

#include <vector>

namespace Common {

	class SceneManager : public Manager {
	public:
		friend class InstanceCollection;

		const static std::string Name;

		void update(float _delta);
		void handleEvent(const sf::Event& _event);
		void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

		void addScene(Scene *_scene);
		void removeScene(Scene *_scene);

		void setActiveScene(Scene *_scene);
		Scene& getActiveScene(void);

	private:
		SceneManager();
		~SceneManager();

		std::vector<Scene *> m_Scenes;
		Scene *m_CurrentScene;
	};

}