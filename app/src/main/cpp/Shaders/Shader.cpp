//
// Created by HP on 01-03-2024.
//

#include "Shader.hpp"

#include "../AXRLogger.cpp"
#include "../AssetManagerHelperJNI.hpp"

#define MAX_LOG_SIZE 512

void Shader::ConstructShader(const char *vertexShaderPath, const char *fragmentShaderPath) {
    ANDROID_LOG_INFO("inside Construct Shader");

    const char* vertexShaderBuffer = jniHelperObject->GetShaderFile(vertexShaderPath);
    const char* fragmentShaderBuffer = jniHelperObject->GetShaderFile(fragmentShaderPath);

    unsigned int vertexShaderID, fragmentShaderID;
    int success;
    char infoLog[MAX_LOG_SIZE];

    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1,&vertexShaderBuffer , NULL);
    glCompileShader(vertexShaderID);

    checkCompileErrors(vertexShaderID, "VERTEX_SHADER");

    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fragmentShaderBuffer, NULL);
    glCompileShader(fragmentShaderID);

    checkCompileErrors(fragmentShaderID, "FRAGMENT_SHADER");

    ANDROID_LOG_INFO("SHADERS::COMPILATION_SUCCESS \n");

    // shader Program
    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    checkCompileErrors(programID, "PROGRAM");

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    // Don't forget to free the memory when you're done
    delete[] vertexShaderBuffer;
    delete[] fragmentShaderBuffer;
}

bool Shader::checkCompileErrors(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            ANDROID_LOG_WARN("ERROR::SHADER_COMPILATION_ERROR of type: %s", type.c_str());
            ANDROID_LOG_WARN("Information on the same: %s", infoLog);

            return false;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            ANDROID_LOG_WARN("ERROR::PROGRAM_LINKING_ERROR of type: %s", type.c_str());
            ANDROID_LOG_WARN("Information on the same: %s", infoLog);

            return false;
        }
    }

    return true;
}

void Shader::use()
{
    glUseProgram(programID);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}
void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]);
}
void Shader::setVec2(const std::string &name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(programID, name.c_str()), x, y);
}
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(programID, name.c_str()), x, y, z);
}
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(programID, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const
{
    glUniform4f(glGetUniformLocation(programID, name.c_str()), x, y, z, w);
}
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
