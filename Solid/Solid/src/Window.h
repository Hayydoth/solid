#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <functional>

class Application;

class Window
{
public:
	struct InitData {
		int size[2];
		std::string title;
		std::function<void()> initCallback;
		std::function<void()> updateCallback;
	};
private:
	GLFWwindow* handle;
	InitData data;

	Window() = default;

	Window(Window&&) = delete;
	Window(const Window&) = delete;
	Window& operator= (Window) = delete;
public:

	static Window& Instance() {
		static Window instance;
		return instance;
	}

	GLFWwindow* GetHandle() {
		return handle;
	}

	void SetInitData(InitData wid) {
		data = wid;
	}

	bool Init();
	void Update();
	void Destroy();
};