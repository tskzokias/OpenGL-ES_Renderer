//
// Created by HP on 01-03-2024.
//

#ifndef CUSTOMLAUNCHER_SHADER_HPP
#define CUSTOMLAUNCHER_SHADER_HPP

#include <EGL/egl.h>
#include "glm/glm.hpp"
#include <GLES3/gl32.h>

#include <string>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

class Shader {
public:
    unsigned int programID;

    Shader() = default;
    void ConstructShader(const char* vertexShader, const char* fragmentShader);
    bool checkCompileErrors(GLuint shader, std::string type);

    // Use the shader
    void use();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    std::string LoadShaderFile(AAssetManager* ssetManager, const std::string& shaderFile);
};


#endif //CUSTOMLAUNCHER_SHADER_HPP
