#pragma once
#include "ecs/Scene.h"

class Window;

class Application
{
private:
	Application() = default;

	Application(Application&&) = delete;
	Application(const Application&) = delete;
	Application& operator= (Application) = delete;
public:
	static Application& Instance() {
		static Application instance;
		return instance;
	}

	SceneState scene;
	bool shouldClose;
	bool Start();
	void Loop();
};