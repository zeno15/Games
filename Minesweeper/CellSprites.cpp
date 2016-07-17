#include "CellSprites.hpp"

#include "Cell.hpp"
#include "../Common/InstanceCollection.hpp"
#include "../Common/TextureManager.hpp"

namespace MineSweeper {

	const std::string CellSprites::Name = "CellSprites";

	CellSprites::CellSprites() {
		auto& texture = Common::InstanceCollection::getInstance<Common::TextureManager>().getTexture("atlas");
		for (unsigned int i = 0; i < Sprite::NumSprites; i += 1) {
			m_Sprites.emplace_back(texture, sf::IntRect(64 * i, 0, 64, 64));
		}
	}

	CellSprites::~CellSprites() {}

	void CellSprites::renderSprite(sf::RenderTarget& _target, Sprite _sprite, unsigned int _x, unsigned int _y) const {
		sf::RenderStates states = sf::RenderStates::Default;
		states.transform.translate(sf::Vector2f(_x * CELL_SIZE, _y * CELL_SIZE));
		states.transform.scale(sf::Vector2f(24.0f / 64.0f, 24.0f / 64.0f));
		_target.draw(m_Sprites[_sprite], states);
	}

}