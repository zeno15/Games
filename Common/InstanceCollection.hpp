#pragma once

#include "Manager.hpp"

#include <map>
#include <string>

namespace Common {

	class InstanceCollection {
	public:
		template <typename T>
		static void registerInstance(void) {
			if (m_Managers.find(T::Name) == m_Managers.end()) {
				m_Managers.insert(std::pair<std::string, Manager *>(T::Name, new T()));
			}
		}
		template <typename T>
		static void registerInstance(T *instance) {
			if (m_Managers.find(T::Name) == m_Managers.end()) {
				m_Managers.insert(std::pair<std::string, Manager *>(T::Name, instance));
			}
		}

		template <typename T>
		static void removeInstance() {
			if (m_Managers.find(T::Name) == m_Managers.end()) {
				throw std::runtime_error(T::Name);
			}

			m_Managers.erase(T::Name);
		}

		template <typename T>
		static void removeInstance(T *instance) {
			if (m_Managers.find(T::Name) == m_Managers.end()) {
				throw std::runtime_error(T::Name);
			}

			m_Managers.erase(T::Name);
		}

		template <typename T>
		static T& getInstance() {
			if (m_Managers.find(T::Name) == m_Managers.end()) {
				throw std::runtime_error(T::Name);
			}

			return *static_cast<T *>(m_Managers[T::Name]);
		}

		static void clear(void);

	private:
		InstanceCollection() {};

		static std::map<std::string, Manager *> m_Managers;
	};

}