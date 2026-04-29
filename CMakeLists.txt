cmake_minimum_required(VERSION 4.3)
project(OpenGL_Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(OpenGL_Engine main.cpp includes/glad/src/glad.c
        main.h
        Graphics/Shader.h
        Renderer/Renderer.h
        Renderer/OpenGLRenderer.h
        Renderer/OpenGLRenderer.cpp
        Platform/Platform.h
        Platform/Platform.cpp
        Graphics/Mesh.h
        Graphics/Material.h
)

target_link_libraries(OpenGL_Engine
    OpenGL::GL
    glfw
)

target_include_directories(OpenGL_Engine PRIVATE
        includes/glad/include
)

# Copy shader files from source to build directory
configure_file(
        ${CMAKE_SOURCE_DIR}/shaders/default.vert
        ${CMAKE_BINARY_DIR}/shaders/default.vert COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/shaders/default.frag
        ${CMAKE_BINARY_DIR}/shaders/default.frag COPYONLY
)