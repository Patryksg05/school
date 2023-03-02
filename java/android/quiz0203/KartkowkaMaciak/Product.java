package com.example.kartkowkarecyclerview;

import java.util.ArrayList;

public class Product {
    private String name;
    private boolean isFlag;

    public static ArrayList<Product> products = new ArrayList<Product>()
    {{
        add(new Product("maslo"));
//        add(new Product("mleko"));
//        add(new Product("banan"));
//        add(new Product("woda"));
//        add(new Product("sok"));
//        add(new Product("ryz"));
//        add(new Product("makaron"));
//        add(new Product("jablko"));
//        add(new Product("arbuz"));
    }};

    public Product(String name) {
        this.name = name;
        this.isFlag = false;
    }

    public static void addProduct(Product product)
    {
        if(!products.contains(product))
            products.add(product);
    }

    public String getName() {
        return name;
    }

    public boolean isFlag() {
        return isFlag;
    }

    public void setFlag(boolean flag) {
        isFlag = flag;
    }

    @Override
    public String toString() {
        return this.name;
    }
}
