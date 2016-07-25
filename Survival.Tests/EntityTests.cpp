#include "stdafx.h"
#include "CppUnitTest.h"

#include <Entity.hpp>
#include <StationaryEntity.hpp>
#include <MobileEntity.hpp>
#include "MockEntity.hpp"
#include "MockMobileEntity.hpp"
#include "NotificationManager.hpp"
#include "../Common/InstanceCollection.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SurvivalTests {
	TEST_CLASS(TileTests) {
	public:
		TEST_METHOD_INITIALIZE(TestInitialize) {
			Common::InstanceCollection::registerInstance<Survival::NotificationManager>();
		}

		TEST_METHOD(MobileEntitiesDontHoldPressure) {
			Survival::MobileEntity& m = MockMobileEntity();

			Assert::IsFalse(m.holdsPressure());
		}
	};
}