#pragma once

#include <memory>

struct GLFWwindow;

namespace SwordSong {
	class Window {
	public:
		Window();
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
		GLFWwindow* window;
	};
}

