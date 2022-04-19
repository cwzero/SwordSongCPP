#pragma once

#include <memory>

namespace SwordSong {
	enum Key;
	class GameWorld;
	class Player;
	class PlayerView;
	class TileGrid;	
	class Game {
		public:
			Game(std::shared_ptr<TileGrid> grid);
			~Game();

			void Initialize();
			void Shutdown();

			void Update();
			void Render(double delta);

			void KeyEvent(Key key);
		private:
			std::shared_ptr<GameWorld> world;
			std::shared_ptr<Player> player;
			std::unique_ptr<PlayerView> view;
			std::shared_ptr<TileGrid> grid;
	};
}