#pragma once

#include <memory>

namespace SwordSong {
	class TileGrid;	
	class Game {
		public:
			Game(std::shared_ptr<TileGrid> tileGrid);
			virtual ~Game();

			virtual void Initialize();
			virtual void Shutdown();

			virtual void Update();
			virtual void Render(double delta);
		private:
			std::shared_ptr<TileGrid> tileGrid;
	};
}