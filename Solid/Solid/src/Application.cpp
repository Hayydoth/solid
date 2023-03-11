#include "Application.h"
#include "Window.h"

#include "ecs/Scene.h"
#include "ecs/components/CMaterial.h"

#include <optick/optick.h>
#include <iostream>

template<typename T>
const auto eac = EntityLogic::AddComponent<T>;

template<typename T>
const auto egc = EntityLogic::GetComponent<T>;

bool Application::Start()
{
	shouldClose = false;

	auto initFunc = [&]() {
		SceneLogic::AddEntity(&scene, "test");
		eac<CMaterial>(SceneLogic::GetEntity(&scene, "test"));
		std::cout << egc<CMaterial>(SceneLogic::GetEntity(&scene, "test"))->cumstring << "\n";
	
		SceneLogic::Start(&scene);
	};

	auto updateFunc = [&]() {
		SceneLogic::Update(&scene);
	};

	Window::InitData wid;
	wid.initCallback = initFunc;
	wid.updateCallback = updateFunc;
	wid.size[0] = 1280; wid.size[1] = 720;
	wid.title = "solid";
	Window::Instance().SetInitData(wid);
	return Window::Instance().Init();
}

void Application::Loop()
{
	while (!Application::shouldClose)
	{
		OPTICK_FRAME("MainThread");

		Window::Instance().Update();
	}
	Window::Instance().Destroy();
}
