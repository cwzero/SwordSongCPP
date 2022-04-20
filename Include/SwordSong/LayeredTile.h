#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
	class LayeredTile : public virtual Drawable {
	public:
		LayeredTile(int layers);
		LayeredTile(int layers, Drawable** layer);
		~LayeredTile();

		virtual void Draw(TileGrid& grid, int x, int y) const;
		void SetLayer(int layer, Drawable* d);
	private:
		int layers;
		Drawable** layer;
	};
}