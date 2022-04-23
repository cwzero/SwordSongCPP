#include "SwordSong/StackTile.h"

namespace SwordSong {
    StackTile::StackTile() {

    }

    StackTile::~StackTile() {

    }

    void StackTile::Draw(TileGrid& grid, int x, int y) const {
        stack.top().Draw(grid, x, y);
    }

    void StackTile::Push(Drawable& d) {
        stack.push(d);
    }

    Drawable& StackTile::Top() {
        return stack.top();
    }

    void StackTile::Pop() {
        stack.pop();
    }

    void StackTile::Remove(Drawable& target) {
        std::stack<Drawable> tmp;

        while (!stack.empty() && (&stack.top() != &target)) {
            tmp.push(stack.top());
            stack.pop();
        }

        if (!stack.empty() && (&stack.top() == &target)) {
            stack.pop();
        }

        while (!tmp.empty()) {
            stack.push(tmp.top());
            tmp.pop();
        }
    }

    bool StackTile::IsEmpty() {
        return stack.empty();
    }

    void StackTile::Clear() {
        while(!stack.empty()) {
            stack.pop();
        }
    }
}