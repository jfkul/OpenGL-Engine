#ifndef OPENGL_ENGINE_RENDERER_H
#define OPENGL_ENGINE_RENDERER_H

#include "../Graphics/Mesh.h"
#include "../Graphics/Texture.h"

#include "../Assets/Image.h"

#include <vector>

class Renderer
{
public:
    virtual void init(int width, int height) = 0;
    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;

    virtual Mesh createMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) = 0;
    virtual void drawMesh(const Mesh& mesh) = 0;

    virtual Texture createTexture(const Image& image) = 0;
};

#endif //OPENGL_ENGINE_RENDERER_H
