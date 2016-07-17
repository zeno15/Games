#pragma once

#include "Manager.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <map>

namespace Common {

	class TextureManager : public Manager {
	public:
		friend class InstanceCollection;

		const static std::string Name;

		void addTexture(const std::string& _filename, const std::string& _textureName);

		sf::Texture& getTexture(const std::string& _textureName);

	private:
		TextureManager();
		~TextureManager();

		std::map<std::string, sf::Texture *> m_Textures;
	};

}