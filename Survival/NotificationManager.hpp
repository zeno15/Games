#pragma once

#include "../Common/Manager.hpp"

#include <vector>
#include <functional>
#include <SFML/System/Vector2.hpp>

namespace Common {
	class InstanceCollection;
}

namespace Survival {

	class NotificationManager : public Common::Manager {
	public:
		friend class Common::InstanceCollection;

		const static std::string Name;

		std::function<void(unsigned int, unsigned int)> tileUpdated;

		std::function<void(unsigned int, unsigned int)> ghostBuiltAt;


	private:
		NotificationManager();
		~NotificationManager();


	};

}