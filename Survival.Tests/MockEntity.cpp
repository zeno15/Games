#include "stdafx.h"
#include "MockEntity.hpp"


MockEntity::MockEntity() :
Survival::Entity(false, false) {

	updatesCalled = 0;
	handleEventsCalled = 0;
	drawsCalled = 0;
}


MockEntity::~MockEntity() {}

void MockEntity::update(float _delta) {
	updatesCalled += 1;
}
void MockEntity::updateTick(void) {
}
void MockEntity::handleEvent(sf::Event _event) {
	handleEventsCalled += 1;
}
void MockEntity::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
	void *d = (void *)(&drawsCalled);

	int *d2 = (int *)d;

	*d2 = drawsCalled + 1;
}

