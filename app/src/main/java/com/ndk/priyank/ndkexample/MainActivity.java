package com.ndk.priyank.ndkexample;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("ceelib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        TextView tv = new TextView(this);

        String jsCode = loadJsAssetsAsString();
        String z = message(jsCode);
        tv.setTextSize(30);
        tv.setText(z);
        setContentView(tv);
    }

    private String loadJsAssetsAsString() {
        StringBuffer jsContentToReturn = new StringBuffer("");
        try {
            String[] listOfFiles = getAssets().list("js");
            if(listOfFiles.length > 0 ) {
                for(String filePath : listOfFiles) {
                    InputStream stream = getAssets().open("js/" + filePath);
                    int size = stream.available();
                    byte[] buffer = new byte[size];
                    stream.read(buffer);
                    stream.close();
                    jsContentToReturn.append(new String(buffer));
                }
            }
        } catch (IOException ioException) {
            return "";
        }
        return jsContentToReturn.toString();
    }

    public String log(String message) {
        Log.e("From JNI -----------> ", message);
        return null;
    }

    public native int add(int a, int b);

    public native String message(String js);

}
