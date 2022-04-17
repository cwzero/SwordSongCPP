#pragma once

#include <memory>

namespace SwordSong {
	class TileGrid;

	class RenderEngine {
	public:
		RenderEngine(std::shared_ptr<TileGrid> tileGrid);
		virtual ~RenderEngine();

		void Initialize();
		void Shutdown();

		void Draw();
	private:
		std::shared_ptr<TileGrid> tileGrid;
	};
}