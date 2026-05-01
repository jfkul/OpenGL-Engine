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
    // positions          // colors           // texture coords
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
};
std::vector<unsigned int> indices = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

int main()
{
    Platform platform {};
    platform.initWindow(kWidth, kHeight, kTitle);

    OpenGLRenderer renderer {};
    renderer.init(kWidth, kHeight);

    platform.setFramebufferSizeCallback(renderer.onResize);

    Mesh rectMesh = renderer.createMesh(vertices, indices);

    Shader textureShader { "shaders/texture.vert", "shaders/texture.frag" };

    Texture container = renderer.createTexture(Image { "Graphics/TestingAssets/container.jpg" });

    if (rectMesh.material)
    {
        rectMesh.material->texture = &container;
        rectMesh.material->shader = textureShader;
    }

    // Rendering loop
    while (!platform.windowShouldClose())
    {
        // Input and events
        processInput(platform);
        platform.pollEvents();  // Check position on this

        // Rendering
        renderer.beginFrame();

        renderer.drawMesh(rectMesh);

        renderer.endFrame();

        // Swap buffers
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