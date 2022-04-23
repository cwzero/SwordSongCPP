#pragma once

#include "SwordSong/Drawable.h"
#include <stack>

namespace SwordSong {
    class StackTile : public virtual Drawable {
    public:
        StackTile();
        ~StackTile();

		virtual void Draw(TileGrid& grid, int x, int y) const override;

        virtual void Push(Drawable& d);
        virtual Drawable& Top();
        virtual void Pop();
        virtual void Remove(Drawable& d);
        virtual void Clear();

        virtual bool IsEmpty();
    private:
        std::stack<Drawable> stack;
    };
}