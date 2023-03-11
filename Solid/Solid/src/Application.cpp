#include "Application.h"
#include "Window.h"

#include "ecs/Scene.h"
#include "ecs/components/CMaterial.h"

#include <optick/optick.h>
#include <iostream>

bool Application::Start()
{
	shouldClose = false;

	auto initFunc = []() {
		SceneState scene = SceneState();
		SceneLogic::AddEntity(&scene, "test");
		EntityLogic::AddComponent<CMaterial>(SceneLogic::GetEntity(&scene, "test"));
		std::cout << EntityLogic::GetComponent<CMaterial>(SceneLogic::GetEntity(&scene, "test"))->cumstring << "\n";
	};

	Window::InitData wid;
	wid.initCallback = initFunc;
	wid.size[0] = 1280; wid.size[1] = 720;
	wid.title = "solid";
	return Window::Init(wid);
}

void Application::Loop()
{
	while (!Application::shouldClose)
	{
		OPTICK_FRAME("MainThread");

		Window::Update();
	}
	Window::Destroy();
}
