#include "TextureManager.hpp"

namespace Common {

	const std::string TextureManager::Name = "TextureManager";

	TextureManager::TextureManager() {}


	TextureManager::~TextureManager() {}


	void TextureManager::addTexture(const std::string& _filename, const std::string& _textureName) {
		if (m_Textures.find(_textureName) == m_Textures.end()) {
			auto t = new sf::Texture();
			if (!t->loadFromFile(_filename)) {
				throw std::runtime_error("Failed to load texture");
			}

			m_Textures.insert(std::pair<std::string, sf::Texture *>(_textureName, t));
		}
	}

	sf::Texture& TextureManager::getTexture(const std::string& _textureName) {
		if (m_Textures.find(_textureName) != m_Textures.end()) {
			return *m_Textures[_textureName];
		}

		throw std::runtime_error("Failed to find texture");
	}

}