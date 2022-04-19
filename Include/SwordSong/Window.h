#pragma once

#include <memory>

struct GLFWwindow;

namespace SwordSong {
	class Engine;
	class Window {
	public:
		Window(Engine *engine);
		~Window();

		void Initialize();
		void Shutdown();

		void MakeCurrent();
		void Clear();
		double GetDelta();
		void SwapBuffers();
		void ProcessInput();

		void GetSize(int *width, int *height);

		bool ShouldClose();
	private:
		Engine *engine;
		GLFWwindow* window;

		void glKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}

