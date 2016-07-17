#pragma once

#include "../Common/Manager.hpp"
#include <SFML/Graphics.hpp>


namespace Common {
	class InstanceCollection;
}


namespace MineSweeper {

	class CellSprites : public Manager {
	public:
		enum Sprite {
			Mines_0,
			Mines_1,
			Mines_2,
			Mines_3,
			Mines_4,
			Mines_5,
			Mines_6,
			Mines_7,
			Mines_8,
			Mines_9,
			Unknown,
			MineFlag,
			Starting,
			Mine,
			NumSprites
		};

		friend class Common::InstanceCollection;

		static const std::string Name;

		void renderSprite(sf::RenderTarget& _target, Sprite _sprite, unsigned int _x, unsigned int _y) const;

	private:
		CellSprites();
		~CellSprites();

		std::vector<sf::Sprite> m_Sprites;
	};

}