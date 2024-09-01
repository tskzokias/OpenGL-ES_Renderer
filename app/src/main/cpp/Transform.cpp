//
// Created by HP on 19-03-2024.
//

#include "Transform.hpp"

glm::mat4 Transform::GetIdentityMatrix() const{
    return glm::mat4(1.0f);
}

glm::mat4 Transform::GetTransformationMatrix() const {
    return transformMatrix;
}

glm::mat4 Transform::Translate(glm::mat4 &tranformationMatrix, glm::vec3 &translateBy) const
{
    return glm::translate(tranformationMatrix, translateBy);
}

glm::mat4 Transform::Rotate(glm::mat4 &tranformationMatrix, float angle, glm::vec3 &rotationAxis) const
{
    return glm::rotate(tranformationMatrix, glm::radians(angle), rotationAxis);
}

glm::mat4 Transform::Scale(glm::mat4 tranformationMatrix, glm::vec3 scaleBy) const
{
    return glm::scale(tranformationMatrix, scaleBy);
}

void Transform::SetTransformMatrix(glm::mat4 matrix)
{
    transformMatrix = matrix;
}
