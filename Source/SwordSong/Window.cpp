#include "SwordSong/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace SwordSong {
	Window::Window() {

	}

	Window::~Window() {

	}

	void glErrorCallback(int err, const char* msg) {
		std::cerr << "Error: " << msg << std::endl;
	}

	static void glKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
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

		window = glfwCreateWindow((int)(mode->width * 0.8), (int)(mode->height * 0.8), "Sword Song", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwSetKeyCallback(window, glKeyCallback);
	}

	void Window::Shutdown() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::MakeCurrent() {
		glfwMakeContextCurrent(window);
		gladLoadGL();
		glfwSwapInterval(1);

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
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
}