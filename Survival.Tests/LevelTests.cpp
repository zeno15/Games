#include "stdafx.h"
#include "CppUnitTest.h"

#include <Tile.hpp>
#include <Level.hpp>
#include "NotificationManager.hpp"
#include "../Common/InstanceCollection.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SurvivalTests {		
	TEST_CLASS(LevelTests) {
	public:

		TEST_METHOD_INITIALIZE(TestInitialize) {
			Common::InstanceCollection::registerInstance<Survival::NotificationManager>();
		}

		TEST_METHOD(DefaultConstructorUsesMinimumSize) {
			auto l = Survival::Level();

			Assert::AreEqual(Survival::Level::MinimumWidth, l.getWidth());
			Assert::AreEqual(Survival::Level::MinimumHeight, l.getHeight());
		}
		
		TEST_METHOD(ConstructorSetsSizeCorrectly) {
			unsigned int w = 22;
			unsigned int h = 26;
			auto l = Survival::Level(w, h);

			Assert::AreEqual(w, l.getWidth());
			Assert::AreEqual(h, l.getHeight());
		}

		TEST_METHOD(LevelResizesItselfToMinimumAllowed) {
			unsigned int w = 5;
			unsigned int h = 3;
			auto l = Survival::Level(w, h);

			Assert::AreEqual(Survival::Level::MinimumWidth, l.getWidth());
			Assert::AreEqual(Survival::Level::MinimumHeight, l.getHeight());
		}

		TEST_METHOD(LevelGeneratesAllTilesForGivenSize) {
			unsigned int w = 12;
			unsigned int h = 16;
			auto l = Survival::Level(w, h);

			for (unsigned int y = 0; y < h; y += 1) {
				for (unsigned int x = 0; x < w; x += 1) {
					auto& t = l.getTile(x, y);
					Assert::AreEqual(x, t.getX());
					Assert::AreEqual(y, t.getY());
				}
			}
		}
	};
}