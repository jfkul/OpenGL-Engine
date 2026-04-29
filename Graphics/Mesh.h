#ifndef OPENGL_ENGINE_MESH_H
#define OPENGL_ENGINE_MESH_H

#include <stddef.h>
#include "Material.h"

struct Mesh
{
    unsigned int VBO;
    unsigned int VAO;
    size_t vertexCount;
    Material* material;
};

#endif //OPENGL_ENGINE_MESH_H
