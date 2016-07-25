#include "ResourceCollection.hpp"

namespace Survival {

	const unsigned int ResourceCollection::Resource::MaxAmount = 1000;
	const std::string ResourceCollection::Resource::WorkName = "Work";

	ResourceCollection::ResourceCollection() {}
	ResourceCollection::ResourceCollection(const std::vector<std::string>& _names) {
		for (auto& n : _names) {
			addResource(Resource(n));
		}
	}

	
	void ResourceCollection::addResource(const Resource& _resource) {
		if (!containsResource(_resource.Name)) {
			m_Resources.push_back(_resource);
			if (m_OnResourcesChanged) m_OnResourcesChanged();
		}
	}
	unsigned int ResourceCollection::addResourceAmount(const std::string& _name, unsigned int _amount) {
		auto& r = getResource(_name);
		unsigned int excessAmount = 0;
		r.Amount += _amount;
		if (r.Amount > r.Max) {
			excessAmount = r.Amount - r.Max;
			r.Amount = r.Max;
		}

		if (m_OnResourcesChanged) m_OnResourcesChanged();

		return excessAmount;
	}

	ResourceCollection::Resource& ResourceCollection::getResource(const std::string& _resourceName) {
		for (auto& r : m_Resources) {
			if (r.Name == _resourceName) {
				return r;
			}
		}
		throw std::runtime_error("Resource '" + _resourceName + "' is not present");
	}
	const ResourceCollection::Resource& ResourceCollection::getResource(const std::string& _resourceName) const {
		for (auto& r : m_Resources) {
			if (r.Name == _resourceName) {
				return r;
			}
		}
		throw std::runtime_error("Resource '" + _resourceName + "' is not present");
	}

	bool ResourceCollection::containsResource(const std::string& _name) {
		for (auto& r : m_Resources) {
			if (r.Name == _name) {
				return true;
			}
		}

		return false;
	}
	bool ResourceCollection::resourceCapped(const std::string& _name) const {
		auto& t = getResource(_name);

		return t.Amount == t.Max;
	}
	bool ResourceCollection::allResourcesCapped(void)  const {
		for (auto& r : m_Resources) {
			if (!resourceCapped(r.Name)) {
				return false;
			}
		}

		return true;
	}
	bool ResourceCollection::allResourcesExceptWorkCapped(void) const{
		for (auto& r : m_Resources) {
			if (r.Name == Resource::WorkName) {
				continue;
			}
			if (!resourceCapped(r.Name)) {
				return false;
			}
		}

		return true;
	}

	void ResourceCollection::dumpResourcesIntoThis(ResourceCollection& _collection) {
		for (auto& r : _collection.m_Resources) {
			dumpResourceIntoThis(r);
		}
	}
	void ResourceCollection::dumpResourceIntoThis(Resource& _resource) {
		if (!containsResource(_resource.Name)) {
			return;
		}

		auto excess = addResourceAmount(_resource.Name, _resource.Amount);

		_resource.Amount = excess;

		if (m_OnResourcesChanged) m_OnResourcesChanged();
	}

	unsigned int ResourceCollection::getResourceCount(void) const {
		return m_Resources.size();
	}
	std::vector<std::string> ResourceCollection::getResourceNames(void) const {
		std::vector<std::string> names;

		for (auto& r : m_Resources) {
			names.push_back(r.Name);
		}

		return names;
	}
	void ResourceCollection::setChangedCallback(std::function<void(void)> _method) {
		m_OnResourcesChanged = _method;
	}
}