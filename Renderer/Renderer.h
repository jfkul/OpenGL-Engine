#ifndef OPENGL_ENGINE_RENDERER_H
#define OPENGL_ENGINE_RENDERER_H

#include "../Graphics/Mesh.h"
#include <vector>

class Renderer
{
public:
    virtual void init(int width, int height) = 0;
    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;

    virtual Mesh createMesh(std::vector<float> vectices) = 0;
    virtual void drawMesh(Mesh mesh) = 0;
    // virtual void DrawMesh() = 0;
};

#endif //OPENGL_ENGINE_RENDERER_H
