#ifndef OPENGL_ENGINE_OPENGLRENDERER_H
#define OPENGL_ENGINE_OPENGLRENDERER_H

#include "Renderer.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer : Renderer
{
public:
    OpenGLRenderer()
        : m_defaultShader { Shader {"shaders/default.vert", "shaders/default.frag"} }
        , m_defaultMaterial { m_defaultShader }
    {
    }

    void init(int width, int height) override;
    void beginFrame() override;
    void endFrame() override;

    Mesh createMesh(std::vector<float> vectices) override;  // Static draw
    void drawMesh(Mesh mesh) override;

    static void onResize(GLFWwindow* window, int width, int height);
private:
    Shader m_defaultShader;
    Material m_defaultMaterial;
};

#endif //OPENGL_ENGINE_OPENGLRENDERER_H
