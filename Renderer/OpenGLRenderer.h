#ifndef OPENGL_ENGINE_OPENGLRENDERER_H
#define OPENGL_ENGINE_OPENGLRENDERER_H

#include <memory>

#include "Renderer.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer : Renderer
{
public:
    OpenGLRenderer()
        : m_defaultShader { Shader { "shaders/default.vert", "shaders/default.frag" } }
        , m_defaultMaterial { Material { m_defaultShader, nullptr } }
    {

    }

    void init(int width, int height) override;
    void beginFrame() override;
    void endFrame() override;

    Mesh createMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) override;  // Static draw
    void drawMesh(const Mesh& mesh) override;

    Texture createTexture(const Image& image) override;

    static void onResize(GLFWwindow* window, int width, int height);
private:
    Shader m_defaultShader;
    Material m_defaultMaterial;
};

#endif //OPENGL_ENGINE_OPENGLRENDERER_H
