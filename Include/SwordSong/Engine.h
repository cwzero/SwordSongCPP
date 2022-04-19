#pragma once

#include "SwordSong/KeyEvent.h"
#include <memory>

namespace SwordSong {
	class Game;
	class RenderEngine;
	class TileGrid;
	class Window;

	class Engine {
	public:
		Engine();
		~Engine();

		void Initialize();
		void Shutdown();

		void Run();
		bool Loop();

		void Update();
		void Render(double delta);

		void KeyEvent(Key key);
	private:
		std::unique_ptr<Game> game;
		std::unique_ptr<RenderEngine> renderEngine;
		std::shared_ptr<TileGrid> grid;
		std::shared_ptr<Window> window;
	};
}