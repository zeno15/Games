#include "SceneManager.hpp"

namespace Common {

	const std::string SceneManager::Name = "SceneManager";

	SceneManager::SceneManager() {
		m_CurrentScene = nullptr;
	}

	SceneManager::~SceneManager() {}


	void SceneManager::update(float _delta) {
		if (m_CurrentScene != nullptr) {
			m_CurrentScene->update(_delta);
		}
	}
	void SceneManager::handleEvent(const sf::Event& _event) {
		if (m_CurrentScene != nullptr) {
			m_CurrentScene->handleEvent(_event);
		}
	}
	void SceneManager::draw(sf::RenderTarget& _target, sf::RenderStates _states) const {
		if (m_CurrentScene != nullptr) {
			m_CurrentScene->draw(_target, _states);
		}
	}

	void SceneManager::addScene(Scene *_scene) {
		m_Scenes.push_back(_scene);
	}
	void SceneManager::removeScene(Scene *_scene) {
		for (unsigned int i = 0; i < m_Scenes.size(); i += 1) {
			if (m_Scenes[i] == _scene) {
				m_Scenes.erase(m_Scenes.begin() + i);
				return;
			}
		}
	}

	void SceneManager::setActiveScene(Scene *_scene) {
		m_CurrentScene = _scene;
	}
	Scene& SceneManager::getActiveScene(void) {
		return *m_CurrentScene;
	}

}