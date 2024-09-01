package com.example.customlauncher;

import android.content.res.AssetManager;
import android.view.KeyEvent;

public class GLES3JNILib {

    static {
        System.loadLibrary("customlauncher");
    }

    public static native void init();

    public static native void passAssetManagerToNative(AssetManager assetManager);
    public static native void DestroyAssetManagerToNative();

    public static native void resize(int width, int height);

    public static native void onVolumeDownPressed();
    public static native void draw();
}
