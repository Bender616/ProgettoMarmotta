package com.example.corsosystem.domusapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity {

    Button btncambio;
    Button btnmenu;
    Button btninfo;
    Button btnrht;
    TextView valTemp;
    TextView valUmidita;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        double fakeTemp = 27.05;
        double fakeRH = 65.05;

        btncambio = (Button)findViewById(R.id.btncambio);
        btnmenu = (Button)findViewById(R.id.btnMenu);
        btninfo = (Button)findViewById(R.id.btninfo);
        btnrht = (Button)findViewById(R.id.btnrht);
        valTemp = (TextView)findViewById(R.id.txtTemperatura);
        valUmidita = (TextView)findViewById(R.id.txtUmidita);

        getTemperature(fakeTemp);
        getUmidita(fakeRH);

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

    public void getTemperature(double p_temp){
        String valore = String.valueOf(p_temp);
        valTemp.setText(valore);

        setColoreTemp(p_temp);
    }

    public void getUmidita(double p_um){
        String valore = String.valueOf(p_um);
        valUmidita.setText(valore);

        setColoreUmidita(p_um);
    }


    public void setColoreTemp(double p_temp) {

         double tempBotLimitSum = 20.0;
         double tempTopLimitSum = 24.0;
         double tempBotLimitWint = 23.0;
         double tempTopLimitWint = 26.0;


         //if() date estate

         if(p_temp > tempTopLimitSum){
             valTemp.setTextColor(getColor(R.color.red));
         }
         if(p_temp < tempBotLimitSum){
             valTemp.setTextColor(getColor(R.color.blue));
         }
         if(p_temp >= tempBotLimitSum && p_temp <= tempTopLimitSum) {
             valTemp.setTextColor(getColor(R.color.green));
         }

    }

    public void setColoreUmidita(double p_um) {
        double relativeHumidityBotLimit = 30.0;
        double relativeHumidityTopLimit = 70.0;

        if(p_um > relativeHumidityTopLimit){
            valUmidita.setTextColor(getColor(R.color.red));
        }
        if(p_um < relativeHumidityBotLimit){
            valUmidita.setTextColor(getColor(R.color.blue));
        }
        if(p_um >= relativeHumidityBotLimit && p_um <= relativeHumidityTopLimit){
            valUmidita.setTextColor(getColor(R.color.green));
        }

    }


}
