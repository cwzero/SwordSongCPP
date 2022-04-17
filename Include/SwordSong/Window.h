#pragma once

#include <memory>

struct GLFWwindow;

namespace SwordSong {
	class Window {
	public:
		Window();
		virtual ~Window();

		virtual void Initialize();
		virtual void Shutdown();

		virtual void MakeCurrent();
		virtual void Clear();
		virtual double GetDelta();
		virtual void SwapBuffers();
		virtual void ProcessInput();

		virtual void GetSize(int *width, int *height);

		virtual bool ShouldClose();
	private:
		GLFWwindow* window;
	};
}

