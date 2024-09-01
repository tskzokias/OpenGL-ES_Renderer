/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 14:03:2024 ****************************************
 ********** FILENAME: AssetManagerJNIHelper.h ************************************/

#ifndef CUSTOMLAUNCHER_ASSETMANAGERHELPERJNI_HPP
#define CUSTOMLAUNCHER_ASSETMANAGERHELPERJNI_HPP

#include <pthread.h>
#include <string>
#include <jni.h>
#include <vector>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

class AssetManagerHelperJNI {
private:
    mutable pthread_mutex_t threadMutex;
    //std::string apkInternalPath;
    AAssetManager *pAssetManager;
    bool volumeDownPressed = false; // VolumeDownKeyPress Event

public:
    AssetManagerHelperJNI(JNIEnv *env, jobject obj, jobject assetManager /*,jstring pathToInternalDir*/);
    char* fileBuffer;

    ~AssetManagerHelperJNI();
    const char* GetShaderFile(const char* filepath, int mode = AASSET_MODE_BUFFER);

    char* GetImageFile(const char* filepath, int& dataSize, int mode = AASSET_MODE_BUFFER);
    bool GetVolumeDownPressedEvent();
    void SetVolumeDownPressedEvent(bool isPressed);
};

extern AssetManagerHelperJNI *jniHelperObject;

#endif //CUSTOMLAUNCHER_ASSETMANAGERHELPERJNI_HPP
