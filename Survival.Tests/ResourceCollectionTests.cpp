#include "stdafx.h"
#include "CppUnitTest.h"

#include <ResourceCollection.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SurvivalTests {
	TEST_CLASS(ResourceCollectionTests) {
	public:
		TEST_METHOD(DefaultResourceCollectionContainsNoResources) {
			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Assert::AreEqual(0u, collection.getResourceCount());
		}

		TEST_METHOD(AddedResourcesAreCorrectlyPersisted) {
			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Survival::ResourceCollection::Resource test1Resource("Test1");

			collection.addResource(test1Resource);

			Assert::AreEqual(1u, collection.getResourceCount());
			Assert::AreEqual(test1Resource.Name, collection.getResourceNames()[0]);
		}

		TEST_METHOD(DefaultResourceAmountAndMaxAmountAreSetCorrectly) {
			Survival::ResourceCollection::Resource test1Resource("Test1");

			Assert::AreEqual(0u, test1Resource.Amount);
			Assert::AreEqual(Survival::ResourceCollection::Resource::MaxAmount, test1Resource.Max);
		}

		TEST_METHOD(AddingResourceWorksAndCannotGoAboveMaxAmount) {
			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Survival::ResourceCollection::Resource test1Resource("Test1");

			collection.addResource(test1Resource);

			Assert::AreEqual(0u, collection.getResource(test1Resource.Name).Amount);
			unsigned int additionAmount = Survival::ResourceCollection::Resource::MaxAmount - 50;

			collection.addResourceAmount(test1Resource.Name, additionAmount);
			Assert::AreEqual(additionAmount, collection.getResource(test1Resource.Name).Amount);

			collection.addResourceAmount(test1Resource.Name, additionAmount);
			Assert::AreEqual(Survival::ResourceCollection::Resource::MaxAmount, collection.getResource(test1Resource.Name).Amount);
		}

		TEST_METHOD(AddingMoreThanTheCollectionIsCapableOfHoldingReturnsTheExcessAmount) {
			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Survival::ResourceCollection::Resource test1Resource("Test1");

			collection.addResource(test1Resource);

			Assert::AreEqual(0u, collection.getResource(test1Resource.Name).Amount);
			unsigned int excessAmount = 50;
			unsigned int additionAmount = Survival::ResourceCollection::Resource::MaxAmount + excessAmount;

			Assert::AreEqual(excessAmount, collection.addResourceAmount(test1Resource.Name, additionAmount));
		}

		TEST_METHOD(DumpingSingleResourceIntoCollectionAddsAndSubtractsCorrectly) {
			std::string resourceName = "ResourceName";

			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Survival::ResourceCollection::Resource test1Resource(resourceName);
			Survival::ResourceCollection::Resource test2Resource(resourceName);

			collection.addResource(test1Resource);

			unsigned int amount = 100;
			test2Resource.Amount = amount;

			collection.dumpResourceIntoThis(test2Resource);

			Assert::AreEqual(0u, test2Resource.Amount);
			Assert::AreEqual(amount, collection.getResource(resourceName).Amount);
		}

		TEST_METHOD(DumpingSingleResourceExcessWorksAsExpected) {
			std::string resourceName = "ResourceName";

			Survival::ResourceCollection collection = Survival::ResourceCollection();

			Survival::ResourceCollection::Resource test1Resource(resourceName);
			Survival::ResourceCollection::Resource test2Resource(resourceName);

			test1Resource.Amount = 600;
			test2Resource.Amount = 600;
			auto expectedAmount = test1Resource.Amount + test2Resource.Amount - test1Resource.Max;
			collection.addResource(test1Resource);

			collection.dumpResourceIntoThis(test2Resource);

			Assert::AreEqual(test1Resource.Max, collection.getResource(resourceName).Amount);
			Assert::AreEqual(expectedAmount, test2Resource.Amount);
		}

		TEST_METHOD(AlternativeConstructorPopulatesResourcesCorrectly) {
			std::vector<std::string> resources = {
				"Resource1",
				"Resource2",
				"Resource3",
				"Resource4",
				"Resource5"
			};


			Survival::ResourceCollection collection = Survival::ResourceCollection(resources);

			for (auto& r : resources) {
				Assert::IsTrue(collection.containsResource(r));
			}
		}
	};
}