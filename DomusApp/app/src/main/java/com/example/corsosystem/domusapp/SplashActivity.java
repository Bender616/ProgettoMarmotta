package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ProgressBar;

public class SplashActivity extends AppCompatActivity {

    private ProgressBar pBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        pBar = (ProgressBar)findViewById(R.id.pBar);

        new Thread(new Runnable() {
            @Override
            public void run() {
                doWork();
                startApp();
                finish();

            }
        }).start();
    }
    private void doWork() {
        for(int progress=0; progress<=100; progress+=1) {
            try {
                Thread.sleep(50);
                pBar.setProgress(progress);
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    private void startApp() {
        Intent intent = new Intent(SplashActivity.this, LoginActivity.class);
        startActivity(intent);
    }
}
