package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class LoginActivity extends AppCompatActivity {

    private EditText user;
    private EditText password;
    private Button login;
    private TextView info;
    private int counter = 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        user = (EditText)findViewById(R.id.editTextUser);
        password = (EditText)findViewById(R.id.editTextPassword);
        info = (TextView)findViewById(R.id.tvInfo);
        login = (Button)findViewById(R.id.buttonLogin);

        info.setText("Tentativi rimasti: 3");

        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                validate(user.getText().toString(), password.getText().toString());
            }
        });
    }
    private void validate(String userName, String Password) {
        if((userName.equals("Admin")) && (Password.equals("Arduino"))) {
            Intent intent = new Intent(LoginActivity.this, MainActivity.class);
            startActivity(intent);
        }else {
            counter--;

            info.setText("Tentativi rimasti: "+String.valueOf(counter));
            Toast.makeText(getApplicationContext(),"Login Errato, riprova!",Toast.LENGTH_SHORT).show();

            if(counter == 0) {
                login.setEnabled(false);
            }
        }
    }
}
