#ifndef OPENGL_ENGINE_IMAGE_H
#define OPENGL_ENGINE_IMAGE_H

#include <iostream>

#include "../includes/stb_image.h"

class Image
{
private:
    int m_width {};
    int m_height {};
    int m_numberOfChannels {};
    unsigned char* m_data { nullptr };
public:
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getChannels() const { return m_numberOfChannels; }
    unsigned char* getData() { return m_data; }
    const unsigned char* getData() const { return m_data; }

    explicit Image(const char* path)
    {
        m_data = stbi_load(path, &m_width, &m_height, &m_numberOfChannels, 0);

        if (!m_data)
            std::cerr << "Failed to load image!\n";
    }

    ~Image()
    {
        stbi_image_free(m_data);
    }

    // Delete copy
    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

    // Move
    Image(Image&& image) noexcept
    {
        m_width = image.m_width;
        m_height = image.m_height;
        m_numberOfChannels = image.m_numberOfChannels;
        m_data = image.m_data;

        image.m_width = 0;
        image.m_height = 0;
        image.m_numberOfChannels = 0;
        image.m_data = nullptr;
    }
    Image& operator=(Image&& image) noexcept
    {
        if (this == &image)
            return *this;

        if (m_data)
            stbi_image_free(m_data);

        m_width = image.m_width;
        m_height = image.m_height;
        m_numberOfChannels = image.m_numberOfChannels;
        m_data = image.m_data;

        image.m_width = 0;
        image.m_height = 0;
        image.m_numberOfChannels = 0;
        image.m_data = nullptr;

        return *this;
    }
};

#endif //OPENGL_ENGINE_IMAGE_H
