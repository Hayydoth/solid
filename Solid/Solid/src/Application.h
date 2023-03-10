#pragma once

class Window;

class Application
{
public:
	static inline bool shouldClose;
	static bool Start();
	static void Loop();
};