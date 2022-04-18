#include "SwordSong/RenderEngine.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	RenderEngine::RenderEngine(std::shared_ptr<TileGrid> grid) {
		this->grid = grid;
	}

	RenderEngine::~RenderEngine() {
		
	}

	void RenderEngine::Initialize() {
		grid->Load();
	}

	void RenderEngine::Shutdown() {
		
	}

	void RenderEngine::Draw() {
		grid->Draw();
	}
}