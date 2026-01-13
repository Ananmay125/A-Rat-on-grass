#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);

    GLFWwindow* window;

    bool ShouldClose();
    void swapBuffer();
    void pollEvents();     
};

#endif