#include "SwordSong/Window.h"
#include "SwordSong/Engine.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace SwordSong {
	Window::Window(Engine* engine) {
		this->engine = engine;
	}

	Window::~Window() {

	}

	void glErrorCallback(int err, const char* msg) {
		std::cerr << "Error: " << msg << std::endl;
	}

	void Window::glKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS || action == GLFW_REPEAT) {
			if (action == GLFW_PRESS && key == GLFW_KEY_ESCAPE) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}
			engine->KeyEvent(getKey(window, key, scancode, action, mods));
		}
	}

	void Window::Initialize() {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback(glErrorCallback);

		if (!glfwInit())
			exit(EXIT_FAILURE);

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		int w = (int)(mode->width * 0.8);
		w -= (w % 16);

		int h = (int)(mode->height * 0.8);
		h -= (h % 16);

		window = glfwCreateWindow(w, h, "Sword Song", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwSetWindowUserPointer(window, this);

		auto func = [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			static_cast<Window*>(glfwGetWindowUserPointer(window))->glKeyCallback(window, key, scancode, action, mods);
		};

		glfwSetKeyCallback(window, func);
	}

	void Window::Shutdown() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::MakeCurrent() {
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glfwSwapInterval(1);

		int width, height;
		GetSize(&width, &height);
		glViewport(0, 0, width, height);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void Window::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	double Window::GetDelta() {
		static double lastTime = 0;
		double currentTime = glfwGetTime();
		double delta = (currentTime - lastTime) * 1000;
		lastTime = currentTime;
		return delta;
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(window);
	}

	void Window::ProcessInput() {
		glfwPollEvents();
	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::GetSize(int* width, int* height) {
		glfwGetWindowSize(window, width, height);
	}
}