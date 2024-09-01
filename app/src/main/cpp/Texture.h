/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: Texture.h **********************************/

#ifndef CUSTOMLAUNCHER_TEXTURE_H
#define CUSTOMLAUNCHER_TEXTURE_H


#include <cassert>
#include <GLES3/gl32.h>

class Texture
{
private:
    int m_width, m_height, m_nrChannels;
    int m_dataSize;

public:
    void SetTexture(const char* filepath, int mode = GL_RGB, int textureWrapping = GL_REPEAT);

    // member Getter Functions
    const int getWidth() const { return m_width; }
    const int getHeight() const { return m_height; }
    const int getNrChannels() const { return m_nrChannels; }
    const int getDataSize() const { return m_dataSize; }

    // member Setter Functions
    void setWidth(int width);
    void setHeight(int height);
    void setNRChannels (int nrChannels);
    void setDataSize (int dataSize);
};


#endif //CUSTOMLAUNCHER_TEXTURE_H
