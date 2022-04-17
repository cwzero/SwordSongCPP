#pragma once

namespace SwordSong {
	class Model {
	public:
		Model();
		virtual ~Model();

		virtual void Initialize();
		virtual void Render();
	private:
		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;
	};
}