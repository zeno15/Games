#pragma once

#include "../Common/Manager.hpp"

#include <functional>

namespace Common {
	class InstanceCollection;
}

namespace Monopoly {

	class NotificationManager : public Common::Manager {
	public:
		friend class Common::InstanceCollection;

		static const std::string Name;

	private:
		NotificationManager();
		~NotificationManager();
	};

}