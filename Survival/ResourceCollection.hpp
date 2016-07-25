#pragma once

#include <vector>
#include <string>
#include <functional>

namespace Survival {

	class ResourceCollection {
	public:
		struct Resource {

			static const unsigned int MaxAmount;
			static const std::string WorkName;

			std::string Name;
			unsigned int Amount;
			unsigned int Max;

			Resource(const std::string& _name, unsigned int _max = MaxAmount) :
			Name(_name),
			Amount(0),
			Max(_max) {}
		};

		ResourceCollection();
		ResourceCollection(const std::vector<std::string>& _names);

		void addResource(const Resource& _resource);
		unsigned int addResourceAmount(const std::string& _name, unsigned int _amount);
		Resource& getResource(const std::string& _resourceName);
		const Resource& getResource(const std::string& _resourceName) const;

		bool containsResource(const std::string& _name);
		bool resourceCapped(const std::string& _name) const;
		bool allResourcesCapped(void) const;
		bool allResourcesExceptWorkCapped(void) const;

		void dumpResourcesIntoThis(ResourceCollection& _collection);
		void dumpResourceIntoThis(Resource& _resource);

		unsigned int getResourceCount(void) const;
		std::vector<std::string> getResourceNames(void) const;

		void setChangedCallback(std::function<void(void)> _method);
		
	private:
		std::vector<Resource> m_Resources;
		std::function<void(void)> m_OnResourcesChanged;
	};

}