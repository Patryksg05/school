package com.example.kartkowkatimer;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {

    private TextView textViewTimer, textViewResults;
    private Button startBtn, stopBtn, resetBtn, saveBtn;

    private ArrayList<String> times = new ArrayList<String>();
    private Double time = 0.0;
    private Timer timer = new Timer();
    private TimerTask timerTask;
    private boolean runner = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textViewTimer = (TextView) findViewById(R.id.textViewTimer);
        textViewResults = (TextView) findViewById(R.id.textViewResults);
        startBtn = (Button) findViewById(R.id.startBtn);
        stopBtn = (Button) findViewById(R.id.stopBtn);
        resetBtn = (Button) findViewById(R.id.resetBtn);
        saveBtn = (Button) findViewById(R.id.saveBtn);

        startBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        start();
                    }
                }
        );

        stopBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        runner = false;
                        timerTask.cancel();
//                        textViewTimer.setText(textViewTimer.getText().toString());
                    }
                }
        );

        resetBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        textViewTimer.setText("00:00:00");
                        time = 0.0;
                        runner = false;
                        timerTask.cancel();
                    }
                }
        );

        saveBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
//                        times.add("00:00:00");
                        runner = false;
                        timerTask.cancel();
                        times.add(textViewTimer.getText().toString());
                        textViewResults.setText(times.toString() + "\n");
                        time = 0.0;
                        textViewTimer.setText("00:00:00");
                    }
                }
        );
    }

    private void start() {
        if(!runner)
        {
            runner = true;
            startTimer();
        }
    }

    private void startTimer() {
        timerTask = new TimerTask() {
            @Override
            public void run() {
                runOnUiThread(new TimerTask() {
                    @Override
                    public void run() {
                        time++;
                        textViewTimer.setText(getTimerText());
                    }
                });
            }
        };
        timer.scheduleAtFixedRate(timerTask, 0, 1000);
    }

    private String getTimerText() {
        int rounded = (int) Math.round(time);
        int seconds = ((rounded % 86400) % 3600) % 60;
        int minutes = ((rounded % 86400) % 3600) / 60;
        int hours = ((rounded % 86400)/3600);
        return formatTime(seconds, minutes, hours);
    }

    private String formatTime(int seconds, int minutes, int hours) {
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        super.onSaveInstanceState(outState);
        outState.putDouble("miliseconds", time);
        outState.putBoolean("runner", runner);
        outState.putStringArrayList("arrayList", times);
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        time = savedInstanceState.getDouble("miliseconds");
        runner = savedInstanceState.getBoolean("runner");
        times = savedInstanceState.getStringArrayList("arrayList");

        textViewResults.setText(times.toString() + " ");

        int rounded = (int) Math.round(time);
        int seconds = ((rounded % 86400) % 3600) % 60;
        int minutes = ((rounded % 86400) % 3600) / 60;
        int hours = ((rounded % 86400)/3600);

        textViewTimer.setText(formatTime(seconds, minutes, hours));

        if(runner)
            startTimer();
    }
}