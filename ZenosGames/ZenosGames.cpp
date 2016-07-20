#include <iostream>
#include <cstdlib>

#include "../Common/InstanceCollection.hpp"
#include "../Common/FontManager.hpp"
#include "../Common/TextureManager.hpp"
#include "../Common/SceneManager.hpp"
#include "../Common/Application.hpp"

// MineSweeper
#include "../Minesweeper/GameScene.hpp"
#include "../Minesweeper/NotificationManager.hpp"

// Tetris
#include "../Tetris/GameScene.hpp"

// SpaceInvaders
#include "../SpaceInvaders/GameScene.hpp"
#include "../SpaceInvaders/ProjectileManager.hpp"
#include "../SpaceInvaders/NotificationManager.hpp"

// Monopoly
#include "../Monopoly/GameScene.hpp"

int main(int argc, char **_argv) {
	Common::InstanceCollection::registerInstance<Common::Application>();
	Common::InstanceCollection::registerInstance<Common::FontManager>();
	Common::InstanceCollection::registerInstance<Common::SceneManager>();
	Common::InstanceCollection::registerInstance<Common::TextureManager>();

	const std::string MineSweeper = "MineSweeper";
	const std::string SpaceInvaders = "SpaceInvaders";
	const std::string Tetris = "Tetris";
	const std::string Monopoly = "Monopoly";

	std::string game = Monopoly;
	Common::Scene *gameScene;
	
	if (game == MineSweeper) {
		Common::InstanceCollection::getInstance<Common::FontManager>().addFont("../Resources/Fonts/MineSweeper/arial.ttf", "arial");
		Common::InstanceCollection::getInstance<Common::TextureManager>().addTexture("../Resources/Textures/MineSweeper/Atlas.png", "atlas");
		Common::InstanceCollection::registerInstance<MineSweeper::NotificationManager>();
		Common::InstanceCollection::registerInstance<MineSweeper::CellSprites>();

		gameScene = new MineSweeper::GameScene();
	}
	else if (game == Tetris) {
		gameScene = new Tetris::GameScene();
	}
	else if (game == Monopoly) {
		gameScene = new Monopoly::GameScene();
	}
	else if (game == SpaceInvaders) {
		Common::InstanceCollection::registerInstance<SpaceInvaders::ProjectileManager>();
		Common::InstanceCollection::registerInstance<SpaceInvaders::NotificationManager>();

		gameScene = new SpaceInvaders::GameScene();
	}
	else {
		throw std::runtime_error("No Game selected for startup");
	}

	Common::InstanceCollection::getInstance<Common::Application>().initialise(sf::Vector2u(1280, 720), game);

	Common::InstanceCollection::getInstance<Common::SceneManager>().addScene(gameScene);
	Common::InstanceCollection::getInstance<Common::SceneManager>().setActiveScene(gameScene);

	Common::InstanceCollection::getInstance<Common::Application>().start();

	return EXIT_SUCCESS;
}