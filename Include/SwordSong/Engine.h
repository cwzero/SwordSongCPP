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
		virtual ~Engine();

		virtual void Initialize();
		virtual void Shutdown();

		virtual void Run();
		virtual bool Loop();

		virtual void Update();
		virtual void Render(double delta);
	private:
		std::unique_ptr<Game> game;
		std::unique_ptr<RenderEngine> renderEngine;
		std::shared_ptr<TileGrid> tileGrid;
		std::unique_ptr<Window> window;
	};
}