#pragma once

#include <memory>

namespace SwordSong {
	class TileGrid;	
	class Game {
		public:
			Game(std::shared_ptr<TileGrid> tileGrid);
			~Game();

			void Initialize();
			void Shutdown();

			void Update();
			void Render(double delta);
		private:
			std::shared_ptr<TileGrid> tileGrid;
	};
}