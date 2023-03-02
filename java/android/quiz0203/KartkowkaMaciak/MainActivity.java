package com.example.kartkowkarecyclerview;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private Button addingBtn, removingBtn;
    private EditText editText;

    private ArrayList<Product> products = Product.products;
    ProductAdapter productAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toast.makeText(this, Integer.toString(products.size()), Toast.LENGTH_SHORT).show();

        recyclerView = (RecyclerView) findViewById(R.id.recyclerView);
        addingBtn = (Button) findViewById(R.id.addingButton);
        removingBtn = (Button) findViewById(R.id.removingButton);
        editText = (EditText) findViewById(R.id.productName);

        productAdapter = new ProductAdapter(this, products);
        recyclerView.setAdapter(productAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        addingBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if(!editText.getText().toString().equals("")) {
                            Product product = new Product(editText.getText().toString());
                            Product.addProduct(product);
                            productAdapter.notifyDataSetChanged();
                            Toast.makeText(MainActivity.this, "Dodano: " +
                                            editText.getText().toString(),
                                    Toast.LENGTH_SHORT).show();
                        }
                        else
                            Toast.makeText(MainActivity.this, "wypelnij!", Toast.LENGTH_SHORT).show();
                    }
                }
        );

        removingBtn.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        productAdapter.removeChecked();
                        productAdapter.notifyDataSetChanged();
                        if(products.size() == 0)
                        {
                            Toast.makeText(MainActivity.this, "why everything? :cc", Toast.LENGTH_SHORT).show();
                        }
                    }
                }
        );

        editText.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        editText.getText().clear();
                    }
                }
        );
     }
}