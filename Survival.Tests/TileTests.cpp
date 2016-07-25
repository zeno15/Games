#include "stdafx.h"
#include "CppUnitTest.h"

#include <Tile.hpp>
#include "MockEntity.hpp"
#include "NotificationManager.hpp"
#include "../Common/InstanceCollection.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SurvivalTests {
	TEST_CLASS(TileTests) {
	public:
		TEST_METHOD_INITIALIZE(TestInitialize) {
			Common::InstanceCollection::registerInstance<Survival::NotificationManager>();
		}

		TEST_METHOD(TileSetsCoordinatesCorrectly) {
			unsigned int x = 123;
			unsigned int y = 23643;
			Survival::Tile t = Survival::Tile(x, y);

			Assert::AreEqual(x, t.getX());
			Assert::AreEqual(y, t.getY());
		}

		TEST_METHOD(TileEntityDefaultsToNullptr) {
			Survival::Tile t = Survival::Tile(0, 0);

			Assert::IsNull(t.getEntity());
		}

		TEST_METHOD(TileEntityIsSetProperly) {
			Survival::Tile t = Survival::Tile(0, 0);

			Survival::Entity& e = MockEntity();

			t.setEntity(&e);

			Assert::AreEqual(&e, t.getEntity());
		}

		TEST_METHOD(TileKnowsIfItHasAnEntity) {
			Survival::Tile t = Survival::Tile(0, 0);

			Survival::Entity& e = MockEntity();

			Assert::IsFalse(t.hasEntity());
			t.setEntity(&e);

			Assert::IsTrue(t.hasEntity());
		}

		TEST_METHOD(UpdatingTileUpdatesEntity) {
			Survival::Tile t = Survival::Tile(0, 0);
			MockEntity& e = MockEntity();
			t.setEntity(&e);

			Assert::AreEqual(0, e.updatesCalled);
			t.update(0.0f);
			Assert::AreEqual(1, e.updatesCalled);
		}
		TEST_METHOD(HandlingEventForTileAlsoDoesOnEntity) {
			Survival::Tile t = Survival::Tile(0, 0);
			MockEntity& e = MockEntity();
			t.setEntity(&e);

			Assert::AreEqual(0, e.handleEventsCalled);
			t.handleEvent(sf::Event());
			Assert::AreEqual(1, e.handleEventsCalled);
		}
		TEST_METHOD(DrawingTileAlsoDrawsEntity) {
			Survival::Tile t = Survival::Tile(0, 0);
			MockEntity& e = MockEntity();
			t.setEntity(&e);

			Assert::AreEqual(0, e.drawsCalled);
			t.draw(sf::RenderWindow(), sf::RenderStates::Default);
			Assert::AreEqual(1, e.drawsCalled);
		}
		TEST_METHOD(SettingEntityNotifiesThatTheTileHasBeenUpdated) {
			bool updated = false;

			auto updateMethod = [&](unsigned int _x, unsigned int _y) {
				updated = true;
			};

			Common::InstanceCollection::getInstance<Survival::NotificationManager>().tileUpdated = updateMethod;

			Survival::Tile t = Survival::Tile(0, 0);
			MockEntity& e = MockEntity();
			t.setEntity(&e);

			Assert::IsTrue(updated);
		}

		TEST_METHOD(HoldsPressureDefaultAndSettingWorks) {
			Survival::Tile t = Survival::Tile(0, 0);

			Assert::IsFalse(t.holdsPressure());
			t.setHoldsPressure(true);
			Assert::IsTrue(t.holdsPressure());
		}
	};
}