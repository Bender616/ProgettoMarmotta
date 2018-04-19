package com.example.corsosystem.domusapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class WebActivity extends AppCompatActivity {

    // WebView wv;
    // String domusweb = "file:///E:/Domus%20Aurea/domusweb.html";
    private WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web);
        webView = (WebView)findViewById(R.id.wv);
        webView.setWebViewClient(new WebViewClient());
        webView.loadUrl("http://192.168.4.1/");

        WebSettings websettings = webView.getSettings();
        websettings.setJavaScriptEnabled(true);

        //wv = (WebView)findViewById(R.id.wv);
        //wv.getSettings().setJavaScriptEnabled(true);
        //wv.setFocusable(true);
        //wv.setFocusableInTouchMode(true);
        //wv.getSettings().setRenderPriority(WebSettings.RenderPriority.HIGH);
        //wv.getSettings().setCacheMode(WebSettings.LOAD_NO_CACHE);
        //wv.getSettings().setDomStorageEnabled(true);
        //wv.getSettings().setDatabaseEnabled(true);
        //wv.getSettings().setAppCacheEnabled(true);
        //wv.setScrollBarStyle(View.SCROLLBARS_INSIDE_OVERLAY);
        //wv.loadUrl(domusweb);

    }
    public void onBackPressed() {
        if(webView.canGoBack()) {
            webView.goBack();
        }else {
            super.onBackPressed();
        }
    }
}
