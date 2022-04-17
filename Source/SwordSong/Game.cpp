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
		tileGrid->SetTile( 0,  0, {{0,  4}, {1, 1, 1}});
		tileGrid->SetTile( 1,  1, {{0,  5}, {1, 0, 1}});
		tileGrid->SetTile( 0,  1, {{0, 11}, {1, 1, 1}});
		tileGrid->SetTile(-1, -1, {{0,  6}, {0, 1, 1}});
		tileGrid->SetTile( 1,  0, {{1, 11}, {1, 1, 1}});
		tileGrid->SetTile( 0, -1, {{2, 11}, {1, 1, 0}});
	}
}