#pragma once

namespace SwordSong {
	class Model {
	public:
		Model();
		virtual ~Model();

		virtual void Initialize();
		virtual void Render();
	private:
		float width, height;
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	};
}