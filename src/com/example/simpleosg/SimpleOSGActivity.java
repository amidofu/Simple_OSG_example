package com.example.simpleosg;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class SimpleOSGActivity extends Activity {

	MyGLSurfaceView mview;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_simple_osg);
        mview=(MyGLSurfaceView)findViewById(R.id.myGLSurfaceView);
        mview.setRenderer(new MyGLRenderer());
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_simple_osg, menu);
        return true;
    }
    
    public void onBackPressed(){
		finish();
    }
}
