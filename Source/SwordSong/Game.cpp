#include "SwordSong/Game.h"
#include "SwordSong/TileGrid.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Game::Game(std::shared_ptr<TileGrid> tileGrid) {
		this->tileGrid = tileGrid;
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

	}
}