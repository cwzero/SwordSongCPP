#include "SwordSong/Game.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/KeyEvent.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/TileGrid.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Game::Game(std::shared_ptr<TileGrid> grid) {
		this->grid = grid;
		this->world = std::make_shared<GameWorld>(500, 500, 5);
		this->player = std::make_shared<Player>(world);
		this->view = std::make_unique<PlayerView>(player, grid->GetWidth(), grid->GetHeight());
	}

	Game::~Game() {

	}

	void Game::Initialize() {
		
	}

	void Game::Shutdown() {

	}

	void Game::Update() {
		static bool added = false;
		if (!added) {
			player->AddToWorld(world.get(), 0, 0, 0);
			added = true;
		}
	}

	void Game::Render(double delta) {
		this->view->Render(*world, *grid);
	}
	
	void Game::KeyEvent(Key key) {
		switch (key) {
			case Up:
				player->MoveNorth();
				break;
			case Right:
				player->MoveEast();
				break;
			case Down:
				player->MoveSouth();
				break;
			case Left:
				player->MoveWest();
				break;
			case Comma:
				player->MoveDown();
				break;
			case Period:
				player->MoveUp();
				break;
			default:
				break;
		}
	}
}