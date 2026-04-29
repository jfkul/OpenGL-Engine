#ifndef OPENGL_ENGINE_SHADER_H
#define OPENGL_ENGINE_SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // Program ID
    unsigned int ID;

    // Read and build shader
    Shader(const char* vertexPath, const char* fragmentPath)
    {
        std::string vertexSource;
        std::string fragmentSource;

        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        // Enable exceptions
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        // Load shader from file
        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);

            std::stringstream vShaderStream;
            std::stringstream fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexSource = vShaderStream.str();
            fragmentSource = fShaderStream.str();
        }
        catch (std::ifstream::failure &e)
        {
            std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
        }

        // Convert to C-style strings for use with OpenGL
        const char* vShaderCode = vertexSource.c_str();
        const char* fShaderCode = fragmentSource.c_str();

        int success;
        char infoLog[512];

        // Compile the vertex shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
        glCompileShader(vertexShader);

        // Check for compilation errors
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
        }

        // Compile the fragment shader
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
        glCompileShader(fragmentShader);

        // Check for compilation errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
        }

        // Create shader program and link the above shaders to it
        ID = glCreateProgram();

        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);  // Links the inputs and outputs of the shaders

        // Check for linking errors
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(ID, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
        }

        // Delete shader objects as they have already been linked to program
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    // Activate shader
    void use()
    {
        glUseProgram(ID);
    }

    // Set uniform value
    void setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
    }
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
};

#endif //OPENGL_ENGINE_SHADER_H
