#pragma once

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
	private:
		std::unique_ptr<Game> game;
		std::unique_ptr<RenderEngine> renderEngine;
		std::shared_ptr<TileGrid> tileGrid;
		std::unique_ptr<Window> window;
	};
}