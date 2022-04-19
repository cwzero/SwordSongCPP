#include "SwordSong/KeyEvent.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwordSong {
	Key getKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
		switch (key) {
		case GLFW_KEY_UP:
			return Up;
			break;
		case GLFW_KEY_RIGHT:
			return Right;
			break;
		case GLFW_KEY_DOWN:
			return Down;
			break;
		case GLFW_KEY_LEFT:
			return Left;
			break;
		case GLFW_KEY_COMMA:
			return Comma;
			break;
		case GLFW_KEY_PERIOD:
			return Period;
		default:
			return Unknown;
		}

		return Unknown;
	}
}