#pragma once

#include "../Common/Manager.hpp"

#include <functional>

namespace Common {
	class InstanceCollection;
}

namespace MineSweeper {

	class Cell;
	class NotificationManager : public Manager {
	public:
		friend class Common::InstanceCollection;

		static const std::string Name;

		std::function<void(Cell *)> RevealCell;
		std::function<void(void)> MarkMine;
		std::function<void(void)> UnMarkMine;

		std::function<void(void)> NotifyWin;
		std::function<void(void)> NotifyLoss;

	private:
		NotificationManager();
		~NotificationManager();
	};

}