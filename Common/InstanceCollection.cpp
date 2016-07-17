#include "InstanceCollection.hpp"

namespace Common {

	std::map<std::string, Manager *> InstanceCollection::m_Managers = std::map<std::string, Manager *>();

	void InstanceCollection::clear(void) {
		for (auto& p : m_Managers) {
			delete p.second;
		}
		m_Managers.clear();
	}

}