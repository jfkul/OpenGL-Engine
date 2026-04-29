#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "main.h"

#include "Graphics/Shader.h"
#include "Graphics/Mesh.h"
#include "Platform/Platform.h"
#include "Renderer/OpenGLRenderer.h"

constexpr int kWidth { 800 };
constexpr int kHeight { 600 };
const char* kTitle { "OpenGL Engine" };

// TESTING DATA
std::vector<float> vertices = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

std::vector<float> vertices2 = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  -1.0f, 0.0f
};

int main()
{
    Platform platform;
    platform.initWindow(kWidth, kHeight, kTitle);

    OpenGLRenderer renderer;
    renderer.init(kWidth, kHeight);

    platform.setFramebufferSizeCallback(renderer.onResize);

    Mesh triangleMesh = renderer.createMesh(vertices);
    Mesh triangleMesh2 = renderer.createMesh(vertices2);

    // Rendering loop
    while (!platform.windowShouldClose())
    {
        // Input
        processInput(platform);
        platform.pollEvents();  // Check position on this

        // Rendering
        renderer.beginFrame();

        renderer.drawMesh(triangleMesh);
        renderer.drawMesh(triangleMesh2);

        renderer.endFrame();

        // Poll events and swap buffers
        platform.presentFrame();
    }

    platform.terminate();
    return 0;
}

void processInput(Platform& platform)
{
    if (platform.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        platform.setWindowShouldClose(true);
    }
}