package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class RHTActivity extends AppCompatActivity {

    Button btnforward;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rht);

        btnforward = (Button)findViewById(R.id.btnforward);

        btnforward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openTestoActivity();
            }
        });

    }
    public void openTestoActivity() {
        Intent intent = new Intent(this, TestoActivity.class);
        startActivity(intent);
    }
}
