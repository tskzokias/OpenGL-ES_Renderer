
#include "AXRGLFunctions.hpp"
#include "AXRLogger.cpp"

bool checkGlError(const char* funcName)
{
    GLint err = glGetError();
    if (err != GL_NO_ERROR) {
        ANDROID_LOG_ERROR("GL error after %s(): 0x%08x\n", funcName, err);
        return true;
    }
    return false;
}

void printGlString(const char* name, GLenum s)
{
    const char* v = (const char*)glGetString(s);
    ANDROID_LOG_VERBOSE("GL %s: %s\n", name, v);
}
