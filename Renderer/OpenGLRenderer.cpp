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

Mesh OpenGLRenderer::createMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
{
    Mesh mesh {};

    // Create and bind Vertex Array Object
    glGenVertexArrays(1, &mesh.VAO);
    glBindVertexArray(mesh.VAO);

    // Create and bind Vertex Buffer Object
    glGenBuffers(1, &mesh.VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Tell OpenGL how to interpret vertex data for vertex attribute at each location
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
        8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Create and bind Element Buffer Object
    glGenBuffers(1, &mesh.EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        indices.data(), GL_STATIC_DRAW);

    mesh.material = &m_defaultMaterial;

    mesh.vertexCount = vertices.size() / 8;
    mesh.indexCount = indices.size();

    return mesh;
}

void OpenGLRenderer::drawMesh(const Mesh& mesh)
{
    if (mesh.material->texture)
        glBindTexture(GL_TEXTURE_2D, mesh.material->texture->ID);

    glBindVertexArray(mesh.VAO);
    mesh.material->shader.use();

    glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, 0);
}

Texture OpenGLRenderer::createTexture(const Image& image)
{
    Texture texture;

    int format = (image.getChannels() == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &texture.ID);

    glBindTexture(GL_TEXTURE_2D, texture.ID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, image.getWidth(), image.getHeight(), 0,
        format, GL_UNSIGNED_BYTE, image.getData());
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    texture.format = format;
    texture.width = image.getWidth();
    texture.height = image.getHeight();

    return texture;
}

void OpenGLRenderer::onResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
