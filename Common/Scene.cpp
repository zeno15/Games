#include "Scene.hpp"

namespace Common {

	Scene::Scene(const std::string& _name) :
		m_Name(_name) {

	}
	Scene::~Scene() {

	}

	std::string Scene::getName(void) const {
		return m_Name;
	}

}