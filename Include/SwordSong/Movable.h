#pragma once

#include "SwordSong/Entity.h"

namespace SwordSong {
	class Movable : public virtual Entity {
	public:
		void MoveNorth();
		void MoveEast();
		void MoveSouth();
		void MoveWest();
		void MoveUp();
		void MoveDown();
		void MoveRelative(int dx, int dy, int dz);
		void MoveTo(int x, int y, int z);
	};
}