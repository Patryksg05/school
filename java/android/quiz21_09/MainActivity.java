package com.example.a21_09_quiz;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.View;
import android.view.accessibility.AccessibilityNodeInfo;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.slider.Slider;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    private ImageView imageView;
    private Slider slider;
    private Spinner spinner;
    private TextView textView;
    private ArrayList<String> images = new ArrayList<String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imageView = (ImageView) findViewById(R.id.imageView);
        slider = (Slider) findViewById(R.id.slider);
        spinner = (Spinner) findViewById(R.id.spinner);
        textView = (TextView) findViewById(R.id.textView);

        images.add("pingwiny1");
        images.add("pingwiny2");
        images.add("pingwiny3");
        images.add("pingwiny4");

        slider.addOnChangeListener(
                new Slider.OnChangeListener() {
                    @Override
                    public void onValueChange(@NonNull Slider slider, float value, boolean fromUser) {
//                        int size = (int) value;
                        textView.setTextSize(value);
                    }
                }
        );

        ArrayAdapter<String> spinnerArrayAdapter = new ArrayAdapter<String>(
                this, android.R.layout.simple_spinner_item, images
        );
        spinnerArrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(spinnerArrayAdapter);
        spinner.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String image = parent.getItemAtPosition(position).toString();
        if(image.equals(images.get(0)))
            imageView.setImageResource(R.drawable.penguin);
        else if(image.equals(images.get(1)))
            imageView.setImageResource(R.drawable.pin1);
        else if(image.equals(images.get(2)))
            imageView.setImageResource(R.drawable.pin2);
        else
            imageView.setImageResource(R.drawable.pin3);
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {
        imageView.setImageResource(R.drawable.pin1);
    }
}