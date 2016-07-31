#pragma once

#include "../Common/Entity.hpp"
#include "RegionEntity.hpp"

namespace Pokemon {


	class Tile : public Common::Entity {
	public:
		static const float Width;
		static const float Height;

		Tile(unsigned int _x, unsigned int _y, unsigned int _spritesheetX, unsigned int _spritesheetY, bool _isRegionJumper = false);
		~Tile();

		// Inherited via Entity
		virtual void update(float _delta) override;
		virtual void handleEvent(sf::Event _event) override;
		virtual void draw(sf::RenderTarget & _target, sf::RenderStates _states) const override;

		virtual void onEntityEntered(RegionEntity *_entity);
		virtual void onEntityLeave(RegionEntity *_entity);
		virtual void onEntityMovedWithin(RegionEntity *_entity);

		unsigned int getX(void) const;
		unsigned int getY(void) const;

		bool isRegionJumper(void) const;
		bool isFree(void) const;
		void reserve(void);
		void free(void);

	private:
		unsigned int m_X;
		unsigned int m_Y;
		unsigned int m_SpriteSheetX;
		unsigned int m_SpriteSheetY;

		bool m_IsFree;
		bool m_IsRegionJumper;

		sf::Sprite m_Sprite;
	};

}