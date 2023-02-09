package com.example.kartkowkalistview;

import static com.example.kartkowkalistview.R.color.*;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.view.menu.ListMenuItemView;

import android.annotation.SuppressLint;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /**
     * toDo:
     *  - lista zakupow:
     *  - wypisujemy: maslo, cukier, chlebek (listViewProducts)
     *  na dobry: lista startowa pusta, dodajemy elementy z
     *  formularza: editText z textem PodajProduct, po kliknieciu
     *  znika naps, dodajemy do tablicy
     *  na bbdb: po kliknieciu sie usuwa
     *  na cel: po kliknieciu zmienia sie tlo elementu // inna czcionka
     */

    ListView listViewProducts;
    EditText editTextProductName;
    Button addProductButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayList<Product> products = Product.products;
        listViewProducts = findViewById(R.id.listViewProducts);
        editTextProductName = findViewById(R.id.editTextProduct);
        addProductButton = findViewById(R.id.addButton);

        ArrayAdapter<Product> productArrayAdapter = new ArrayAdapter<>(
                this, android.R.layout.simple_list_item_1, products
        );

        listViewProducts.setAdapter(productArrayAdapter);

        addProductButton.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        String productName = editTextProductName.getText().toString();
                        Toast.makeText(MainActivity.this, productName, Toast.LENGTH_SHORT).show();
                        Product product = new Product(productName);
                        Product.addProductToArray(product);
                        productArrayAdapter.notifyDataSetChanged();
                    }
                }
        );

        listViewProducts.setOnItemClickListener(
                new AdapterView.OnItemClickListener() {
                    @Override
                    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                        Toast.makeText(MainActivity.this, parent.getItemAtPosition(position).toString(),
                                Toast.LENGTH_SHORT).show();

                        products.remove(position);
                        productArrayAdapter.notifyDataSetChanged();
                        if(products.size()==0)
                            Toast.makeText(MainActivity.this, "why everything? :cc", Toast.LENGTH_SHORT).show();
                    }
                }
        );

//        listViewProducts.setOnItemClickListener(
//                new AdapterView.OnItemClickListener() {
//                    @SuppressLint("ResourceAsColor")
//                    @Override
//                    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
//                        view.setBackgroundColor(Color.RED);
//                    }
//                }
//        );

        editTextProductName.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        editTextProductName.setText(" ");
                    }
                }
        );

    }
}