#pragma once

namespace SwordSong {
	class Model {
	public:
		Model();
		~Model();

		void Initialize();
		void Render();
	private:
		float width, height;
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	};
}