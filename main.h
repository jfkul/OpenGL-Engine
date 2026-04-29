#ifndef OPENGL_ENGINE_MAIN_H
#define OPENGL_ENGINE_MAIN_H

#include <GLFW/glfw3.h>

#include "Platform/Platform.h"

void processInput(Platform& platform);

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

#endif //OPENGL_ENGINE_MAIN_H
