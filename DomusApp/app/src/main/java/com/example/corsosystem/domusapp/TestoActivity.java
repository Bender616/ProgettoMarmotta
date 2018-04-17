package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class TestoActivity extends AppCompatActivity {

    Button btnforward2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_testo);

        btnforward2 = (Button)findViewById(R.id.btnforward2);

        btnforward2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openTesto2Activity();
            }
        });
    }
    public void openTesto2Activity() {
        Intent intent = new Intent(this, Testo2Activity.class);
        startActivity(intent);
    }
}
