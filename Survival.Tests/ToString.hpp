#pragma once

#include "Entity.hpp"

#include <sstream>


namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {

			template <>
			static std::wstring ToString(Survival::Entity* q) {
				auto v = (uintptr_t)q;

				std::wstringstream ss;

				ss << v;

				return ss.str();
			}

		}
	}
}