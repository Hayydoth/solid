#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <functional>

class Application;

class Window
{
private:
	static inline GLFWwindow* handle;
public:
	struct InitData {
		int size[2];
		std::string title;
		std::function<void()> initCallback;
	};

	static GLFWwindow* GetHandle() {
		return handle;
	}

	static bool Init(InitData data);
	static void Update();
	static void Destroy();
};