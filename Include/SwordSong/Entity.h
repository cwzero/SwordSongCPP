#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
	class Entity : public Drawable {
	public:
		virtual void Update() = 0;

		inline int GetX() { return x; }
		inline int GetY() { return y; }
		inline int GetZ() { return z; }
	private:
		int x, y, z;
	};
}