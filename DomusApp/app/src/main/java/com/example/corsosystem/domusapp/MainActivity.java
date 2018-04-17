package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    Button btncambio;
    Button btnmenu;
    Button btninfo;
    Button btnrht;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btncambio = (Button)findViewById(R.id.btncambio);
        btnmenu = (Button)findViewById(R.id.btnMenu);
        btninfo = (Button)findViewById(R.id.btninfo);
        btnrht = (Button)findViewById(R.id.btnrht);

        btninfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openActivity4();
            }
        });

        btnmenu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openActivity3();
            }
        });

        btncambio.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openActivity2();
            }
        });
        btnrht.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openRHTActivity();
            }
        });
    }
    public void openRHTActivity() {
        Intent intent = new Intent(this, RHTActivity.class);
        startActivity(intent);
    }

    public void openActivity2() {
        Intent intent = new Intent(this, Main2Activity.class);
        startActivity(intent);
    }
    public void openActivity3() {
        Intent intent = new Intent(this, Main3Activity.class);
        startActivity(intent);
    }
    public void openActivity4() {
        Intent intent = new Intent(this, Main4Activity.class);
        startActivity(intent);
    }


}
