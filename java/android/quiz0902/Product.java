package com.example.kartkowkalistview;

import java.util.ArrayList;

public class Product {
    private String name;

    public Product(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public static ArrayList<Product> products = new ArrayList<Product>() {
        {
            add(new Product("Maslo"));
        }
    };

    private boolean isProductInArray(Product product)
    {
        return products.contains(product);
    }

    public static void addProductToArray(Product product)
    {
        if(!product.isProductInArray(product))
            products.add(product);
    }

    @Override
    public String toString() {
        return this.name;
    }
}
