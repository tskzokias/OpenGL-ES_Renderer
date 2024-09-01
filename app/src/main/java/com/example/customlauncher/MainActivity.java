package com.example.customlauncher;

import static com.example.customlauncher.GLES3JNILib.onVolumeDownPressed;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.view.KeyEvent;
import android.widget.TextView;

import com.example.customlauncher.databinding.ActivityMainBinding;

public class MainActivity extends Activity {
    CustomGLView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        mView = new CustomGLView(getApplication());

        GLES3JNILib.passAssetManagerToNative(getAssets());
        setContentView(mView);
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event)
    {
        if (keyCode == KeyEvent.KEYCODE_VOLUME_DOWN) {
            // Call the native method
            GLES3JNILib.onVolumeDownPressed();
            return true; // Indicate that we have handled the event
        }
        return false;
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
    }

    @Override protected void onDestroy()
    {
        super.onDestroy();

        GLES3JNILib.DestroyAssetManagerToNative();
    }
}