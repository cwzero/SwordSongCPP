#include "SwordSong/Game.h"
#include "SwordSong/BSPGenerator.h"
#include "SwordSong/Drawing.h"
#include "SwordSong/GameWorld.h"
#include "SwordSong/KeyEvent.h"
#include "SwordSong/Player.h"
#include "SwordSong/PlayerView.h"
#include "SwordSong/StaticTile.h"
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
			/*
			StaticTile *floor = new StaticTile({{0, 11}, {0, 1, 0}});
			for (int x = -10; x < 11; x++) {
				for (int y = -10; y < 11; y++) {
					world->SetBackground(250+x, 250+y, 0, floor);
				}
			}
			*/

			//DrawRoom(*world, { 0, 0, 1 }, { 0, 1, 0 }, { 245, 245, 0, 10, 10 });

			BSPGenerator* gen = new BSPGenerator();
			gen->Generate(*world);

			player->AddToWorld(world.get(), 250, 250, 0);
			view->SetPosition(250, 250, 0);

			added = true;
		}
		this->view->Update();
	}

	void Game::Render(double delta) {
		grid->Clear();
		this->view->Render(*world, *grid);
	}

	void Game::KeyEvent(Key key) {
		switch (key) {
		case Key::Up:
			player->MoveNorth();
			break;
		case Key::Right:
			player->MoveEast();
			break;
		case Key::Down:
			player->MoveSouth();
			break;
		case Key::Left:
			player->MoveWest();
			break;
		case Key::Comma:
			player->MoveDown();
			break;
		case Key::Period:
			player->MoveUp();
			break;
		default:
			break;
		}
	}
}