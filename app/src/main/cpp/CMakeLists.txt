# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Declares and names the project.

project("customlauncher")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")
if (${ANDROID_PLATFORM_LEVEL} LESS 12)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 \
                      (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(GL3STUB_SRC gl3stub.c)
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL} LESS 12)

# Import the CMakeLists.txt for the glm library
add_subdirectory(glm) # if your CMakeLists is at '../cpp'
# add_subdirectory(src/main/cpp/glm) # if your CMakeLists is at '../app'


add_library( # Sets the name of the library.
        customlauncher

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${GL3STUB_SRC}
        JNICalls/JNICalls.cpp

        AssetManagerHelperJNI.cpp
        AssetManagerHelperJNI.hpp

        Texture.h
        Texture.cpp

        #Renderer/AXRRenderer.cpp
        AXRLogger.cpp
        AXRGLFunctions.hpp
        AXRGLFunctions.cpp

        Transform.cpp
        Transform.hpp

        Shaders/Shader.hpp
        Shaders/Shader.cpp

        Shapes/Triangle.hpp
        Shapes/Triangle.cpp
        Shapes/Rectangle.hpp
        Shapes/Rectangle.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        customlauncher
        ${OPENGL_LIB}
        android
        EGL
        log
        m
        glm
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})