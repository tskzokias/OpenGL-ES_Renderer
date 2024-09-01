/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 14:03:2024 ****************************************
 ********** FILENAME: AssetManagerJNIHelper.cpp ************************************/

#include "AssetManagerHelperJNI.hpp"
#include <android/input.h>

#include "AXRLogger.cpp"

AssetManagerHelperJNI::AssetManagerHelperJNI(JNIEnv *env, jobject obj, jobject assetManager
                                             /*,jstring pathToInternalDir*/) {
    pAssetManager = AAssetManager_fromJava(env, assetManager);
}

AssetManagerHelperJNI::~AssetManagerHelperJNI() {
    pthread_mutex_destroy( &threadMutex);

    if(fileBuffer)
        delete[] fileBuffer;
}

const char* AssetManagerHelperJNI::GetShaderFile(const char* filepath, int mode)
{
    AAsset* asset = AAssetManager_open(pAssetManager, filepath, mode);
    off_t fileCharacterLength;
    if(asset)
    {
        fileCharacterLength = AAsset_getLength(asset);
        ANDROID_LOG_INFO("File Character Read Length: %d", fileCharacterLength);

        fileBuffer = new char[fileCharacterLength + 1];

        AAsset_read(asset, fileBuffer, fileCharacterLength);
        fileBuffer[fileCharacterLength] = '\0';

        AAsset_close(asset);
    }
    else
        ANDROID_LOG_ERROR("Unable to load File at given path");

    return fileBuffer;
}

char* AssetManagerHelperJNI::GetImageFile(const char* filepath, int& dataSize, int mode)
{
    AAsset* asset = AAssetManager_open(pAssetManager, filepath, mode);
    if(asset)
    {
        dataSize = AAsset_getLength(asset);
        ANDROID_LOG_INFO("File Character Read Length: %d", dataSize);

        fileBuffer = new char[dataSize + 1];

        AAsset_read(asset, fileBuffer, dataSize);
        fileBuffer[dataSize] = '\0';

        ANDROID_LOG_INFO("File Character Read Length strlen: %d", strlen(fileBuffer));
        AAsset_close(asset);
    }
    else
        ANDROID_LOG_ERROR("Unable to load File at given path");

    return fileBuffer;
}

bool AssetManagerHelperJNI::GetVolumeDownPressedEvent() {
    return volumeDownPressed;
}

void AssetManagerHelperJNI::SetVolumeDownPressedEvent(bool isPressed)
{
    volumeDownPressed = isPressed;
}
