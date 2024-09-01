/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 14:03:2024 ****************************************
 ********** FILENAME: JNICalls.cpp **********************************/

#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <string>
#include "../AXRLogger.cpp"

#include "JNICalls.hpp"

#include "../AssetManagerHelperJNI.hpp"
#include "../Shapes/Rectangle.hpp"

#include "../AXRGLFunctions.hpp"

AssetManagerHelperJNI* jniHelperObject = nullptr;
static IShape* shapeObj = nullptr;

extern "C" {
JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_init(JNIEnv* env, jclass obj);
JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_resize(JNIEnv* env, jclass obj, jint width, jint height);
JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_draw(JNIEnv* env, jclass obj);
JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_passAssetManagerToNative(JNIEnv *env, jclass obj, jobject asset_manager);
JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_DestroyAssetManagerToNative(JNIEnv *env, jclass clazz);
};

#if !defined(DYNAMIC_ES3)
static GLboolean gl3stubInit() {
    return GL_TRUE;
}
#endif

extern "C" JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_init(JNIEnv* env, jclass obj) {
    if (shapeObj)
    {
        delete shapeObj;
        shapeObj = NULL;
    }

    printGlString("Version", GL_VERSION);
    printGlString("Vendor", GL_VENDOR);
    printGlString("Renderer", GL_RENDERER);
    printGlString("Extensions", GL_EXTENSIONS);

    const char* versionStr = (const char*)glGetString(GL_VERSION);

    // AjnaXR supports ES3 rendering
    if (strstr(versionStr, "OpenGL ES 3.") && gl3stubInit())
    {
        Rectangle* renderer = createRectangle();
        if(renderer)
            shapeObj = renderer;
    }
    else
        ANDROID_LOG_ERROR("Unsupported OpenGL ES version, OpenGL ES2 supported");
}

extern "C" JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_resize(JNIEnv* env, jclass obj, jint width, jint height) {
    if (shapeObj)
        shapeObj->SetViewport(width, height);
}

extern "C" JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_draw(JNIEnv* env, jclass obj) {
    if (shapeObj)
        shapeObj->Render();
}

extern "C" JNIEXPORT void JNICALL Java_com_example_customlauncher_GLES3JNILib_passAssetManagerToNative(JNIEnv *env, jclass obj,
                                                                     jobject asset_manager)
{
    if(!jniHelperObject)
        jniHelperObject = new AssetManagerHelperJNI(env, obj,asset_manager);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_customlauncher_GLES3JNILib_DestroyAssetManagerToNative(JNIEnv *env, jclass clazz)
{
    if(jniHelperObject)
    {
        delete jniHelperObject;
        jniHelperObject = nullptr;
    }

    if(shapeObj)
    {
        delete shapeObj;
        shapeObj = nullptr;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_customlauncher_GLES3JNILib_onVolumeDownPressed(JNIEnv *env, jclass thiz)
{
    ANDROID_LOG_WARN("VOLUME DOWN PRESSED");

    jniHelperObject->SetVolumeDownPressedEvent(true);
}

//TODO: Create Destroy method