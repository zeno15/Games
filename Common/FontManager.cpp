#include "FontManager.hpp"

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>


std::string get_working_path() {
	char temp[512];
	return (_getcwd(temp, 512) ? std::string(temp) : std::string(""));
}

namespace Common {

	const std::string FontManager::Name = "FontManager";

	FontManager::FontManager() {}


	FontManager::~FontManager() {}


	void FontManager::addFont(const std::string& _filename, const std::string& _fontName) {
		if (m_Fonts.find(_fontName) == m_Fonts.end()) {
			auto t = new sf::Font();
			if (!t->loadFromFile(_filename)) {
				auto cwd = get_working_path();
				throw std::runtime_error("Failed to load font");
			}

			m_Fonts.insert(std::pair<std::string, sf::Font *>(_fontName, t));
		}
	}

	sf::Font& FontManager::getFont(const std::string& _fontName) {
		if (m_Fonts.find(_fontName) != m_Fonts.end()) {
			return *m_Fonts[_fontName];
		}

		throw std::runtime_error("Failed to find font");
	}

}
