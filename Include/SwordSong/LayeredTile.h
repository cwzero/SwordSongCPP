#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
	class LayeredTile : public virtual Drawable {
	public:
		LayeredTile(int layers);
		~LayeredTile();
	private:
		int layers;
		Drawable** layer;
	};
}