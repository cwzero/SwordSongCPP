#pragma once

namespace SwordSong {
	class Game {
		public:
			Game();
			virtual ~Game();

			virtual void Initialize();
			virtual void Shutdown();

			virtual void Update();
			virtual void Render(double delta);
		private:

	};
}