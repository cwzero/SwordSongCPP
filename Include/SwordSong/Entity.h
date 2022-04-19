#pragma once

#include "SwordSong/Drawable.h"

namespace SwordSong {
	class GameWorld;
	class Entity : public Drawable {
	public:
		virtual void Update() = 0;

		inline int GetX() { return x; }
		inline int GetY() { return y; }
		inline int GetZ() { return z; }

		void AddToWorld(GameWorld *world, int x, int y, int z);
		void RemoveFromWorld(GameWorld *world);
	protected:
		GameWorld *world;
		int x = 0, y = 0, z = 0;
	};
}