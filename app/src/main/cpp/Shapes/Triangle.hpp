/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: Triangle.hpp ************************************/

#ifndef CUSTOMLAUNCHER_TRIANGLE_HPP
#define CUSTOMLAUNCHER_TRIANGLE_HPP

#include "IShape.hpp"
#include "../Shaders/Shader.hpp"

#include <GLES3/gl32.h>
#include <EGL/egl.h>

#define NUM_OF_INSTANCES 1

class Triangle : public IShape
{
private:
    GLuint VBO;
    GLuint VAO;
    GLuint texture;
    Shader shader;

public:
    Triangle();

    virtual bool Init();
    virtual void SetViewport(int width, int height);
    virtual void Render();

    virtual ~Triangle();
};


#endif //CUSTOMLAUNCHER_TRIANGLE_HPP
