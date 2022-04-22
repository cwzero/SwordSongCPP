#include "SwordSong/Space.h"

namespace SwordSong {
    Space::Space() {
        foreground = nullptr;
        midground = std::make_unique<StackTile>();
        background = nullptr;
    }

	void Space::Draw(TileGrid& grid, int x, int y) const {
        if (foreground) {
            foreground->Draw(grid, x, y);
        } else {
            if (!midground->IsEmpty()) {
                midground->Draw(grid, x, y);
            } else {
                if (background) {
                    background->Draw(grid, x, y);
                }
            }
        }
    }

    void Space::SetForeground(Drawable *fg) {
        this->foreground = fg;
    }

    void Space::PushMidground(Drawable *mg) {
        midground->Push(mg);
    }

    Drawable *Space::PopMidground() {
        return midground->Pop();
    }

    void Space::RemoveMidground(Drawable *mg) {
        midground->Remove(mg);
    }

    void Space::SetBackground(Drawable *bg) {
        background = bg;
    }
}