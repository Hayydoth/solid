#include "Application.h"
#include "Window.h"

#include "ecs/Scene.h"
#include "ecs/components/CMaterial.h"

#include <iostream>

bool Application::Start()
{
	shouldClose = false;

	auto initFunc = []() {
		Scene scene = Scene();
		scene.AddEntity("test");
		scene.GetEntity("test")->AddComponent<CMaterial>();
		std::cout << scene.GetEntity("test")->GetComponent<CMaterial>()->cumstring << "\n";
	};

	Window::InitData wid;
	wid.initCallback = initFunc;
	wid.size[0] = 1280; wid.size[1] = 720;
	wid.title = "solid";
	return Window::Init(wid);
}

void Application::Loop()
{
	Window::Update();
	Window::Destroy();
}
