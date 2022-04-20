#include "SwordSong/LayeredTile.h"

namespace SwordSong {
	LayeredTile::LayeredTile(int layers) {
		this->layers = layers;
		this->layer = new Drawable*[layers];
	}

	LayeredTile::~LayeredTile() {
		delete[] layer;
	}
}