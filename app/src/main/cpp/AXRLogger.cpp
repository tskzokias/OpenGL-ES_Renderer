/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 14:03:2024 ****************************************
 ********** FILENAME: AXRLogger.cpp ************************************/

#include <android/log.h>

#define LOG_TAG "CustomLauncherAndroid"
#define  ANDROID_LOG_DEBUG(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  ANDROID_LOG_ERROR(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  ANDROID_LOG_VERBOSE(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,__VA_ARGS__)
#define  ANDROID_LOG_INFO(...)  __android_log_print(ANDROID_LOG_INFO   , LOG_TAG,__VA_ARGS__)
#define  ANDROID_LOG_WARN(...)  __android_log_print(ANDROID_LOG_WARN   , LOG_TAG,__VA_ARGS__)
#define  ANDROID_LOG_FATAL(...)  __android_log_print(ANDROID_LOG_FATAL   , LOG_TAG,__VA_ARGS__)
//#define  ANDROID_LOG_SIMPLE(...)