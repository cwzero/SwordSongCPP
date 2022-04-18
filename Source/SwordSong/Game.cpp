#include "SwordSong/Game.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/TileGrid.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Game::Game(std::shared_ptr<TileGrid> grid) {
		this->grid = grid;
		this->world = std::make_unique<GameWorld>();
		this->player = std::make_shared<Player>();
		this->view = std::make_unique<PlayerView>(player);
	}

	Game::~Game() {

	}

	void Game::Initialize() {
		
	}

	void Game::Shutdown() {

	}

	void Game::Update() {

	}

	void Game::Render(double delta) {
		this->view->Render(*world, *grid);
	}
}