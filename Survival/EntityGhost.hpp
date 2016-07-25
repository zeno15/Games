#pragma once

#include "StationaryEntity.hpp"
#include "ResourceCollection.hpp"

namespace Survival {
	class EntityGhost : public StationaryEntity {
	public:
		EntityGhost(Entity *_completeEntity, const ResourceCollection& _resourcesRequired) :
		StationaryEntity(false, true),
		m_CompleteEntity(_completeEntity),
		m_ResourcesRequired(_resourcesRequired){
			m_CompleteEntity->changeAlpha(0.5f);
		}
		~EntityGhost() {

		}

		// Inherited via StationaryEntity
		virtual void update(float _delta) override {}
		virtual void updateTick(void) override {}
		virtual void handleEvent(sf::Event _event) override {}
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override {
			m_CompleteEntity->draw(_target, _states);
		}

		void unGhost(void) {
			m_CompleteEntity->changeAlpha(1.0f);
		}

		Entity *getCompleteEntity(void) {
			return m_CompleteEntity;
		}

		const ResourceCollection& getNeededResources(void) const {
			return m_ResourcesRequired;
		}
		ResourceCollection& getNeededResources(void) {
			return m_ResourcesRequired;
		}

	private:
		Entity *m_CompleteEntity;
		ResourceCollection m_ResourcesRequired;
	};

}