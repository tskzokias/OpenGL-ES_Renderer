/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: Rectangle.cpp ************************************/

#include "Rectangle.hpp"
#include "../AssetManagerHelperJNI.hpp"

#include <chrono>

//float GetTime();
void PrintMat4(glm::mat4 mat);
float getCurrentTime();

glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
};

// Glass shader setting up environments
glm::vec3 cubePositions2[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 0.0f,  2.0f, -10.0f)
};

Rectangle* createRectangle()
{
    Rectangle* renderer = new Rectangle;
    if (!renderer->Init()) {
        delete renderer;
        return NULL;
    }
    ANDROID_LOG_INFO("Rectangle Renderer creation successfully completed\n");
    return renderer;
}

bool Rectangle::Init() {

    const float vertices[] = {
            // positions                      // colors                     // textures
             0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  1.0f,  1.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 1.0f,0.0f, 1.0f,  0.0f,
            -0.5f,-0.5f, 0.0f,0.0f,0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f,1.0f,1.0f, 0.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 2,   // first triangle
            0, 2, 3    // second triangle
    };

    float cubeVertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    ANDROID_LOG_INFO("Rectangle Init \n");
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glGenVertexArrays(NUM_OF_INSTANCES, VAO);
    glGenBuffers(NUM_OF_INSTANCES, VBO);
    glGenBuffers(NUM_OF_INSTANCES, EBO);

    glBindVertexArray(VAO[0]);
    //glBindVertexArray(VAO[1]);

    ANDROID_LOG_INFO("Setting texture wrapping/filtering options \n");

    imageTexture.SetTexture("container.jpg", GL_RGB);

    glGenTextures(1, &texture[1]);
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    // smiley faces
    imageTexture.SetTexture("img.png", GL_RGBA);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ANDROID_LOG_INFO("Binding and copy to buffer is done till here\n");
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    ANDROID_LOG_INFO("Before setting up the Position Attribute \n");
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // For having only positional attributes

    ANDROID_LOG_INFO("Before setting up the Color Attribute \n");
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); // For having color attribute after position attribute

    ANDROID_LOG_INFO("Before setting up the Texture Attribute \n");
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    ANDROID_LOG_INFO("I should go forward for opening the file now \n");
    const char* pathToVertexShader = "shaderPrograms/VertexShader.vert";
    const char* pathToFragmentShader = "shaderPrograms/FragmentShader.frag";
    shader.ConstructShader(pathToVertexShader, pathToFragmentShader);

    glEnable(GL_DEPTH_TEST);

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.use();

    //glUniform1i(glGetUniformLocation(shader.programID, "ourTexture"), 0);
    /*transform.SetTransformMatrix(transform.GetIdentityMatrix());
    transform.SetTransformMatrix(transform.Translate(transform.GetTransformationMatrix(), glm::vec3(0.5, -0.5, 0.5)));
    transform.SetTransformMatrix(transform.Rotate(transform.GetTransformationMatrix(), GetTime(), glm::vec3(0.0, 0.0, 1.0)));*/

    //shader.setMat4("transform", transform.GetTransformationMatrix());

    shader.setInt("Texture1", 0);
    shader.setInt("Texture2", 1);

    /******** BEGINNING OF 3D**********************/

    //glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    /*********** BEGINNING OF CAMERA ************************/
    // TODO: Implement Cameras, classes and all necessary functions
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); // ORIGIN
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

    return true; //TODO: return false wherever required
}

void Rectangle::SetViewport(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Rectangle::Render()
{
    /*shader.use();*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glBindVertexArray(VAO[0]);

    //static float i = 0.0f;

    static float opacityLerp = 0.0f;

    // activate the texture unit first before binding texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    // activate the texture unit first before binding texture
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    if (jniHelperObject->GetVolumeDownPressedEvent())
    {
        ANDROID_LOG_INFO("Volume Down Pressed, Current opacityLerp: , %f", opacityLerp);
        // Perform the action
        opacityLerp += 0.1f;
        shader.setFloat("OpacityLerp", opacityLerp);

        // Reset the flag
        jniHelperObject->SetVolumeDownPressedEvent(false);
    }

    //i += 0.01f;
    /*shader.setMat4("model", model);
    model = glm::rotate(model, glm::radians(0.1f), glm::vec3(0.5f, 1.0f, 0.0f));*/

    //glBindVertexArray(VAO);
    /*for(unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 0.0f * i;
        static float rotate = 0.5f;

        if(i % 3 == 0)
        {
            angle = 20.0f * i;
            rotate += 0.1f;
            model = glm::rotate(model, glm::radians(angle + rotate), glm::vec3(1.0f, 0.3f, 0.5f));
        }
        else
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }*/

    // Send Time for Rotation of Angles
        /*transform.SetTransformMatrix(transform.GetIdentityMatrix());
        transform.SetTransformMatrix(transform.Translate(glm::vec3(0.5, -0.5, 0.5)));
        transform.SetTransformMatrix(transform.Rotate(++i, glm::vec3(0.0, 0.0, 1.0)));*/

        /*ANDROID_LOG_INFO("--------IDENTITY---------------------------");
        glm::mat4 transform1 = transform.GetIdentityMatrix(); // make sure to initialize matrix to identity matrix first
    PrintMat4(transform1);
    ANDROID_LOG_INFO("-------------TRANSLATE----------------------");
        glm::vec3 translateVar = glm::vec3(0.5f, -0.5f, 0.0f);
        transform1 = transform.Translate(transform1, translateVar);
    PrintMat4(transform1);
    ANDROID_LOG_INFO("---------------ROTATE--------------------");
        glm::vec3 rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
        transform1 = transform.Rotate(transform1, ++i, rotationAxis);
    PrintMat4(transform1);
        ANDROID_LOG_INFO("------------NEW-----------------------");*/

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // create transformations
    glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 projection    = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f);
    view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    // pass transformation matrices to the shader
    shader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    shader.setMat4("view", view);

        for(int ind = 0; ind < 2; ++ind)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions2[ind]);

            shader.use();
            glBindVertexArray(VAO[0]);
            shader.setMat4("model", model);
            //unsigned int transformLoc = glGetUniformLocation(shader.programID, "transform");
            //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform1));
            //shader.setMat4("transform", transform1);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }

    /*ANDROID_LOG_INFO("--------IDENTITY---------------------------");
    glm::mat4 transform2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    PrintMat4(transform2);
    ANDROID_LOG_INFO("--------TRANSLATE---------------------------");
    transform2 = glm::translate(transform2, glm::vec3(-0.5f, 0.5f, 0.0f));
    PrintMat4(transform2);
    ANDROID_LOG_INFO("--------ROTATE---------------------------");
    float sinValue = glm::sin(++i);
    transform2 = glm::scale(transform2, glm::vec3(sinValue, sinValue,sinValue));
    PrintMat4(transform2);
    ANDROID_LOG_INFO("--------NEW---------------------------");*/

    //glBindVertexArray(0);

    //glBindVertexArray(VAO[1]);
    /*unsigned int transformLoc1 = glGetUniformLocation(shader.programID, "transform");
    glUniformMatrix4fv(transformLoc1, 1, GL_FALSE, &transform2[0][0]);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);*/

}

Rectangle::Rectangle()
    : VAO{0}, VBO{0}, EBO{}, texture{0}
{

}

Rectangle::~Rectangle()
{
    glDeleteVertexArrays(NUM_OF_INSTANCES, VAO);

    glDeleteBuffers(NUM_OF_INSTANCES, VBO);
    glDeleteBuffers(NUM_OF_INSTANCES, EBO);
    glDeleteBuffers(NUM_OF_INSTANCES, texture);
}

void PrintMat4(glm::mat4 mat)
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            ANDROID_LOG_INFO("%d  ", mat[i][j]);
        }
        ANDROID_LOG_INFO("\n");
    }
}

float getCurrentTime()
{
    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto elapsed = currentTime - startTime;
    auto seconds = std::chrono::duration_cast<std::chrono::duration<float>>(elapsed).count();
    return seconds;
}

// Get the Depth Calculated from the camera position to the object getting rendered
float CalculateDepth(glm::vec3 cameraPosition, glm::vec3 objectPosition)
{
    float x = objectPosition.x - cameraPosition.x;
    float y = objectPosition.y - cameraPosition.y;
    float z = objectPosition.z - cameraPosition.z;
    return glm::sqrt(x*x + y*y + z*z);

}