#include "SwordSong/RenderEngine.h"
#include "SwordSong/TileGrid.h"

namespace SwordSong {
	RenderEngine::RenderEngine(std::shared_ptr<TileGrid> tileGrid) {
		this->tileGrid = tileGrid;
		tileGrid->SetTile(0, 0, {{0, 4}, {1, 1, 1}});
	}

	RenderEngine::~RenderEngine() {
		
	}

	void RenderEngine::Initialize() {
		tileGrid->Load();
	}

	void RenderEngine::Shutdown() {
		
	}

	void RenderEngine::Draw() {
		tileGrid->Draw();
	}
}