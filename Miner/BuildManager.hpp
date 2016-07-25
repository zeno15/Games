#pragma once

#include "../Common/Manager.hpp"

namespace Common {
	class InstanceCollection;
}

namespace Miner {

	class BuildManager : public Common::Manager {
	public:
		friend class Common::InstanceCollection;

		const static std::string Name;

	private:
		BuildManager();
		~BuildManager();
	};

}