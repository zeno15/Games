#include <iostream>
#include <cstdlib>

#include "../Common/InstanceCollection.hpp"
#include "../Common/FontManager.hpp"
#include "../Common/TextureManager.hpp"
#include "../Common/SceneManager.hpp"
#include "../Common/Application.hpp"

#include "../Minesweeper/GameScene.hpp"
#include "../Minesweeper/NotificationManager.hpp"

int main(int argc, char **_argv) {
	Common::InstanceCollection::registerInstance<Common::Application>();
	Common::InstanceCollection::registerInstance<Common::FontManager>();
	Common::InstanceCollection::registerInstance<Common::SceneManager>();
	Common::InstanceCollection::registerInstance<Common::TextureManager>();


	Common::InstanceCollection::registerInstance<MineSweeper::NotificationManager>();
	Common::InstanceCollection::getInstance<Common::FontManager>().addFont("../Resources/Fonts/MineSweeper/arial.ttf", "arial");
	Common::InstanceCollection::getInstance<Common::TextureManager>().addTexture("../Resources/Textures/MineSweeper/Atlas.png", "atlas");
	Common::InstanceCollection::registerInstance<MineSweeper::CellSprites>();

	Common::InstanceCollection::getInstance<Common::Application>().initialise(sf::Vector2u(1280, 720), "Retribution");

	auto gameScene = new MineSweeper::GameScene();

	Common::InstanceCollection::getInstance<Common::SceneManager>().addScene(gameScene);
	Common::InstanceCollection::getInstance<Common::SceneManager>().setActiveScene(gameScene);

	Common::InstanceCollection::getInstance<Common::Application>().start();

	return EXIT_SUCCESS;
}