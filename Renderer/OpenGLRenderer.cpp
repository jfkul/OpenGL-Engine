#include "glad/glad.h"
#include "OpenGLRenderer.h"

void OpenGLRenderer::init(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGLRenderer::beginFrame()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::endFrame()
{
    // Nothing for now
}

Mesh OpenGLRenderer::createMesh(std::vector<float> vertices)
{
    Mesh mesh {};

    // Create and bind Vertex Array Object
    glGenVertexArrays(1, &mesh.VAO);
    glBindVertexArray(mesh.VAO);

    // Create and bind Vertex Buffer Object
    glGenBuffers(1, &mesh.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Tell OpenGL how to interpret vertex data for vertex attribute at location 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    mesh.material = &m_defaultMaterial;

    mesh.vertexCount = vertices.size() / 3;

    return mesh;
}

void OpenGLRenderer::drawMesh(Mesh mesh)
{
    glBindVertexArray(mesh.VAO);
    mesh.material->shader.use();

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderer::onResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
