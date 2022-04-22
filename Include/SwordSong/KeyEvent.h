#pragma once

struct GLFWwindow;

namespace SwordSong {
	enum class Key {
		Unknown, Up, Right, Down, Left, Comma, Period
	};

	Key getKey(GLFWwindow* window, int key, int scancode, int action, int mods);
}