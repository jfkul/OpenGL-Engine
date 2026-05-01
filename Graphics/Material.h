#ifndef OPENGL_ENGINE_MATERIAL_H
#define OPENGL_ENGINE_MATERIAL_H

#include "Shader.h"
#include "Texture.h"

struct Material
{
    Shader& shader;
    Texture* texture { nullptr };
};

#endif //OPENGL_ENGINE_MATERIAL_H
