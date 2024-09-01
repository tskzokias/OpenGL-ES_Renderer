//
// Created by HP on 19-03-2024.
//

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef CUSTOMLAUNCHER_TRANSFORMATION_HPP
#define CUSTOMLAUNCHER_TRANSFORMATION_HPP


class Transform
{
private:
    glm::mat4 transformMatrix { glm::mat4(1.0f) };

public:
    Transform() = default;
    ~Transform() = default;

    glm::mat4 GetIdentityMatrix() const;

    glm::mat4 GetTransformationMatrix() const;
    void SetTransformMatrix(glm::mat4 matrix);

    glm::mat4 Translate(glm::mat4 &transformMatrix, glm::vec3 &translateBy) const;

    /*
     *
     * */
    glm::mat4 Rotate(glm::mat4 &transformMatrix, float angle, glm::vec3 &rotationAxis) const;

    glm::mat4 Scale(glm::mat4 tranformationMatrix, glm::vec3 scaleBy) const;
};


#endif //CUSTOMLAUNCHER_TRANSFORMATION_HPP
