/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: Rectangle.hpp ************************************/

#ifndef CUSTOMLAUNCHER_RECTANGLE_HPP
#define CUSTOMLAUNCHER_RECTANGLE_HPP

#include <GLES3/gl32.h>
#include "IShape.hpp"
#include "../AXRLogger.cpp"
#include "../Shaders/Shader.hpp"
#include "../Transform.hpp"

#include "../Texture.h"

#define NUM_OF_INSTANCES 2

class Rectangle :  public IShape {

private:
    GLuint VAO[NUM_OF_INSTANCES];
    GLuint VBO[NUM_OF_INSTANCES];
    GLuint EBO[NUM_OF_INSTANCES];
    GLuint texture[NUM_OF_INSTANCES];
    Shader shader;
    Texture imageTexture;
    Transform transform;

    glm::mat4 model = glm::mat4(1.0f);

public:
    Rectangle();

    virtual bool Init();
    virtual void SetViewport(int width, int height);
    virtual void Render();

    virtual ~Rectangle();

};

Rectangle* createRectangle();

#endif //CUSTOMLAUNCHER_RECTANGLE_HPP
