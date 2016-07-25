#pragma once

#include <Entity.hpp>

class MockEntity : public Survival::Entity {
public:
	MockEntity();
	~MockEntity();

	// Inherited via Entity
	virtual void update(float _delta) override;
	virtual void updateTick(void) override;
	virtual void handleEvent(sf::Event _event) override;
	virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

	int updatesCalled;
	int handleEventsCalled;
	int drawsCalled;

};

