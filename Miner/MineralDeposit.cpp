#include "MineralDeposit.hpp"

namespace Miner {

	MineralDeposit::MineralDeposit() {}


	MineralDeposit::~MineralDeposit() {}

	void MineralDeposit::update(float _delta) {}

	void MineralDeposit::updateTick(void) {}

	void MineralDeposit::handleEvent(sf::Event _event) {}

	void MineralDeposit::draw(sf::RenderTarget & _target, sf::RenderStates _states) const {
		sf::CircleShape c(8.0f);
		c.setOrigin(8.0f, 8.0f);
		c.setFillColor(sf::Color::Cyan);
		_target.draw(c, _states);
	}

}