#pragma once

#include "../Common/Manager.hpp"

#include <functional>

namespace Common {
	class InstanceCollection;
}

namespace SpaceInvaders {

	class NotificationManager : public Common::Manager {
	public:
		friend class Common::InstanceCollection;

		const static std::string Name;

		std::function<void(void)> NotifyPlayerWon;
		std::function<void(void)> NotifyPlayerLost;

	private:
		NotificationManager();
		~NotificationManager();
	};

}