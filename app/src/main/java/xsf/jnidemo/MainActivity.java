package xsf.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button btnJni1,btnJni2;
    private TextView tvShowInfo;
    private NDKUtils jniUtil;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();

    }

    private void init() {
        jniUtil = new NDKUtils();
        btnJni1 = (Button) findViewById(R.id.btnJni1);
        btnJni1.setOnClickListener(this);
        btnJni2 = (Button) findViewById(R.id.btnJni2);
        btnJni2.setOnClickListener(this);
        tvShowInfo = (TextView) findViewById(R.id.tvShowInfo);

    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btnJni1:
                tvShowInfo.setText(jniUtil.getVipString());
                break;
            case R.id.btnJni2:
                //传入key拿到加密后的key
                break;
        }


    }
}
