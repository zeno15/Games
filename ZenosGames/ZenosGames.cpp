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

// Survival
#include "../Survival/GameScene.hpp"
#include "../Survival/NotificationManager.hpp"
#include "../Survival/BuildingManager.hpp"
#include "../Survival/LevelManager.hpp"

// Miner
#include "../Miner/GameScene.hpp"
#include "../Miner/BuildManager.hpp"

// Pokemon
#include "../Pokemon/GameScene.hpp"
#include "../Pokemon/RegionManager.hpp"



int main(int argc, char **_argv) {
	Common::InstanceCollection::registerInstance<Common::Application>();
	Common::InstanceCollection::registerInstance<Common::FontManager>();
	Common::InstanceCollection::registerInstance<Common::SceneManager>();
	Common::InstanceCollection::registerInstance<Common::TextureManager>();

	const std::string MineSweeper = "MineSweeper";
	const std::string SpaceInvaders = "SpaceInvaders";
	const std::string Tetris = "Tetris";
	const std::string Monopoly = "Monopoly";
	const std::string Survival = "Survival";
	const std::string Miner = "Miner";
	const std::string Pokemon = "Pokemon";

	std::string game = Pokemon;
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
	else if (game == Survival) {
		Common::InstanceCollection::registerInstance<Survival::NotificationManager>();
		Common::InstanceCollection::registerInstance<Survival::BuildingManager>();
		Common::InstanceCollection::registerInstance<Survival::LevelManager>();
		gameScene = new Survival::GameScene();
	}
	else if (game == Miner) {
		gameScene = new Miner::GameScene();
		Common::InstanceCollection::registerInstance<Miner::BuildManager>();
	}
	else if (game == Pokemon) {
		Common::InstanceCollection::registerInstance<Pokemon::RegionManager>();
		Common::InstanceCollection::getInstance<Common::TextureManager>().addTexture("../Resources/Pokemon/TileSheets/TileSheet.png", "Tiles");
		gameScene = new Pokemon::GameScene();
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