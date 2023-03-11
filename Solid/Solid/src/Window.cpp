#include "Window.h"
#include "Application.h"

#include <iostream>

bool Window::Init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    handle = glfwCreateWindow(data.size[0], data.size[1], data.title.c_str(), NULL, NULL);
    if (handle == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glClearColor(.15f, .15f, .15f, 1.0f);
    
    data.initCallback();

    std::cout << "Started successfully.\n";
    return true;
}

void Window::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    data.updateCallback();

    glfwSwapBuffers(handle);
    glfwPollEvents();
    if (glfwWindowShouldClose(handle)) { Application::Instance().shouldClose = true; }
}

void Window::Destroy()
{
    glfwDestroyWindow(handle);
    glfwTerminate();
}
