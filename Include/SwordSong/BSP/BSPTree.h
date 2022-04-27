#pragma once

#include <memory>

namespace SwordSong {
	class GameWorld;
	namespace BSP {
		class BSPNode;

		typedef void (*BSPCallback)(GameWorld& world, BSPNode* node);

		class BSPTree {
		public:
			BSPTree(int width, int height);
			~BSPTree();

			inline BSPNode* GetRoot() {
				return root.get();
			}

			void Split();
			void Iterate(GameWorld& world, BSPCallback callback);
			void Connect();
		private:
			std::unique_ptr<BSPNode> root;
		};
	}
}