#pragma once

#include "Manager.hpp"

#include <SFML/Graphics/Font.hpp>

#include <map>

namespace Common {

	class FontManager : public Manager {
	public:
		friend class InstanceCollection;

		const static std::string Name;

		void addFont(const std::string& _filename, const std::string& _fontName);

		sf::Font& getFont(const std::string& _fontName);

	private:
		FontManager();
		~FontManager();

		std::map<std::string, sf::Font *> m_Fonts;
	};

}