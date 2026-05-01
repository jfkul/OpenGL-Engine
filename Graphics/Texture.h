//
// Created by jk on 4/30/26.
//

#ifndef OPENGL_ENGINE_TEXTURE_H
#define OPENGL_ENGINE_TEXTURE_H

#include <glad/glad.h>

struct Texture
{
    unsigned int ID;
    int format { GL_RGB };
    int width;
    int height;
};

#endif //OPENGL_ENGINE_TEXTURE_H
