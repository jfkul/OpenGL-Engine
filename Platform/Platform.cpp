#include "Platform.h"

void Platform::initWindow(int width, int height, const char* title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (m_window == nullptr)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);

    // Initialise GLAD
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD\n";
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void Platform::pollEvents()
{
    glfwPollEvents();
}

void Platform::presentFrame()
{
    glfwSwapBuffers(m_window);
}

void Platform::terminate()
{
    glfwTerminate();
}

bool Platform::windowShouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void Platform::setWindowShouldClose(int value)
{
    glfwSetWindowShouldClose(m_window, value);
}

int Platform::getKey(int key) const
{
    return glfwGetKey(m_window, key);
}

GLFWframebuffersizefun Platform::setFramebufferSizeCallback(GLFWframebuffersizefun callback)
{
    return glfwSetFramebufferSizeCallback(m_window, callback);
}
