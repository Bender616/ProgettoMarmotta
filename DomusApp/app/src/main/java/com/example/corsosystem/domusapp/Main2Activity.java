package com.example.corsosystem.domusapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class Main2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
    }
    public void onClickDati(View v) {
        Toast.makeText(getApplicationContext(),"Temperatura Impostata Manualmente",Toast.LENGTH_SHORT).show();
        Log.i("onClickDati",".............");
    }
    public void onClickAutomatico(View v) {
        Toast.makeText(getApplicationContext(),"Temperatura Impostata su Automatico",Toast.LENGTH_SHORT).show();
        Log.i("onClickAutomatico",".............");
    }
}
