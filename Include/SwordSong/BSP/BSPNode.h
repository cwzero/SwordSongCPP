#pragma once

#include <memory>

namespace SwordSong {
	class GameWorld;
	struct _Room;
	typedef struct _Room Room;

	namespace BSP {
		class BSPNode;

		typedef void (*BSPCallback)(GameWorld& world, BSPNode* node);

		enum class SplitType {
			Horizontal, Vertical
		};

		class BSPNode {
		public:
			BSPNode(int x, int y, int width, int height);
			BSPNode(int width, int height);
			~BSPNode();

			void Split();
			void Iterate(GameWorld& world, BSPCallback callback);
			void Connect();

			Room GetInternal(int z);

			inline bool IsLeaf() {
				return leftChild.get() == nullptr && rightChild.get() == nullptr;
			}

			inline int GetX() {
				return x;
			}

			inline int GetY() {
				return y;
			}

			inline int GetWidth() {
				return width;
			}

			inline int GetHeight() {
				return height;
			}
		private:
			bool ShouldSplitHorizontal();
			bool ShouldSplitVertical();

			void DoConnect();

			void SplitHorizontal();
			void SplitVertical();

			int x, y;
			int width, height;
			SplitType type;

			std::unique_ptr<BSPNode> leftChild, rightChild;
		};
	}
}