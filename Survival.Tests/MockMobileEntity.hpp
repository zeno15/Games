#pragma once

#include <MobileEntity.hpp>

class MockMobileEntity : public Survival::MobileEntity {
public:
	MockMobileEntity();
	~MockMobileEntity();

	// Inherited via MobileEntity
	virtual void update(float _delta) override;
	virtual void updateTick(void) override;
	virtual void handleEvent(sf::Event _event) override;
	virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;
};

