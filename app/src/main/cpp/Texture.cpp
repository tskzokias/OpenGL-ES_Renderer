/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: Texture.cpp **********************************/

#include "Texture.h"

#include "AXRLogger.cpp"
#include <GLES3/gl32.h>
#include "AssetManagerHelperJNI.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

void Texture::SetTexture(const char *filepath, int mode, int textureWrapping)
{
// set the texture wrapping (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrapping);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrapping);

    // set filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //int width, height, nrChannels; int dataSize;
    stbi_set_flip_vertically_on_load(true);
    char* image = jniHelperObject->GetImageFile(filepath, m_dataSize);
    if (image) //!imageData.empty()
    {
        unsigned char* data = stbi_load_from_memory(
                (const unsigned char*)image,
                m_dataSize, &m_width, &m_height, &m_nrChannels, 0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, mode, m_width, m_height, 0, mode, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            ANDROID_LOG_INFO("Texture loaded successfully \n");
            stbi_image_free(data);
        }
        else
        {
            ANDROID_LOG_ERROR("Failed to load texture: %s ", stbi_failure_reason());
        }
    }
    else
    {
        ANDROID_LOG_ERROR("Image data is empty \n");
    }
}

void Texture::setWidth(int width)
{
    // Assert if width is less than 0
    assert(width >= 0);

    // If the assertion didn't fail, it's safe to set the width
    m_width = width;
}
void Texture::setHeight(int height)
{
    // Assert if width is less than 0
    assert(height >= 0);

    // If the assertion didn't fail, it's safe to set the width
    m_height = height;
}
void Texture::setNRChannels (int nrChannels)
{
    // Assert if width is less than 0
    assert(nrChannels >= 0);

    // If the assertion didn't fail, it's safe to set the width
    m_nrChannels = nrChannels;
}
void Texture::setDataSize (int dataSize)
{
    // Assert if width is less than 0
    assert(dataSize >= 0);

    // If the assertion didn't fail, it's safe to set the width
    m_dataSize = dataSize;
}
