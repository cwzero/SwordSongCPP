#include "SwordSong/LayeredTile.h"

namespace SwordSong {
	LayeredTile::LayeredTile(int layers) {
		this->layers = layers;
		this->layer = new Drawable*[layers];
		for (int i = 0; i < layers; i++) {
			layer[i] = nullptr;
		}
	}
	
	LayeredTile::LayeredTile(int layers, Drawable** layer) : LayeredTile(layers) {
		for (int i = 0; i < layers; i++) {
			this->layer[i] = layer[i];
		}
	}

	LayeredTile::~LayeredTile() {
		delete[] layer;
	}

	void LayeredTile::Draw(TileGrid& grid, int x, int y) const {
		for (int i = 0; i < layers; i++) {
			Drawable *d = layer[i];
			if (d) {
				d->Draw(grid, x, y);
			}
		}
	}

	void LayeredTile::SetLayer(int layer, Drawable* d) {
		this->layer[layer] = d;
	}
}