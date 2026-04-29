#ifndef OPENGL_ENGINE_PLATFORM_H
#define OPENGL_ENGINE_PLATFORM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Platform
{
private:
    GLFWwindow* m_window;
public:
    void initWindow(int width, int height, const char* title);
    void pollEvents();
    void presentFrame();

    void terminate();

    GLFWwindow* getWindow() { return m_window; }

    bool windowShouldClose();
    void setWindowShouldClose(int value);

    int getKey(int key) const;

    GLFWframebuffersizefun setFramebufferSizeCallback(GLFWframebuffersizefun callback);

};

#endif //OPENGL_ENGINE_PLATFORM_H
