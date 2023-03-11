#include "Window.h"
#include "Application.h"

#include <iostream>
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    // setup platform/renderer bindings
    if (!ImGui_ImplGlfw_InitForOpenGL(handle, true)) { return false; }
    if (!ImGui_ImplOpenGL3_Init("#version 330")) { return false; }

    glClearColor(.15f, .15f, .15f, 1.0f);
    
    data.initCallback();

    std::cout << "Started successfully.\n";
    return true;
}

void Window::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    data.updateCallback();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("cummers");
    ImGui::End();
    
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(handle);
    glfwPollEvents();
    if (glfwWindowShouldClose(handle)) { Application::Instance().shouldClose = true; }
}

void Window::Destroy()
{
    glfwDestroyWindow(handle);
    glfwTerminate();
}
