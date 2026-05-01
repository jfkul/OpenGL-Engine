#ifndef OPENGL_ENGINE_MESH_H
#define OPENGL_ENGINE_MESH_H

#include <stddef.h>
#include "Material.h"

struct Mesh
{
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    size_t vertexCount;
    size_t indexCount;
    Material* material;
};

#endif //OPENGL_ENGINE_MESH_H
