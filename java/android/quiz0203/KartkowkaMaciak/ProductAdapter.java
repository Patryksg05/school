package com.example.kartkowkarecyclerview;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.ContentInfo;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.view.menu.MenuView;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.transition.Hold;

import java.util.ArrayList;

public class ProductAdapter extends RecyclerView.Adapter<ProductAdapter.ProductViewHolder> {

    LayoutInflater inflater;
    private ArrayList<Product> products = new ArrayList<Product>();

    public ProductAdapter(Context context, ArrayList<Product> products) {
        this.inflater = LayoutInflater.from(context);
        this.products = products;
    }

    @NonNull
    @Override
    public ProductAdapter.ProductViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = inflater.inflate(R.layout.one_item_row, parent, false);
        return new ProductViewHolder(itemView, this);
    }

    @Override
    public void onBindViewHolder(@NonNull ProductAdapter.ProductViewHolder holder,
                                 @SuppressLint("RecyclerView") final int position) {
        holder.productName.setText(products.get(position).getName());
        holder.productName.setTextColor(Color.BLACK);
        holder.productName.setPaintFlags(
                holder.productName.getPaintFlags() &
                        ~Paint.STRIKE_THRU_TEXT_FLAG
        );
//        products.get(getItemViewType(position)).setFlag(false);
        holder.productName.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if(!products.get(getItemViewType(position)).isFlag())
                        {
                            products.get(getItemViewType(position)).setFlag(true);
                            holder.productName.setPaintFlags(
                                    holder.productName.getPaintFlags() |
                                            Paint.STRIKE_THRU_TEXT_FLAG
                            );
                            holder.productName.setTextColor(Color.RED);
                        }
                        else
                        {
                            products.get(getItemViewType(position)).setFlag(false);
                            holder.productName.setPaintFlags(
                                    holder.productName.getPaintFlags() &
                                            ~Paint.STRIKE_THRU_TEXT_FLAG
                            );
                            holder.productName.setTextColor(Color.BLACK);
                        }
                    }
                }
        );
    }

    public void removeChecked()
    {
        products.removeIf(Product::isFlag);
        notifyDataSetChanged();
    }

    public int getItemViewType(int position) {return position;}


    @Override
    public int getItemCount() {
        return products.size();
    }

    public class ProductViewHolder extends RecyclerView.ViewHolder{
        ProductAdapter productAdapter;
        private final TextView productName;
        public ProductViewHolder(@NonNull View itemView, ProductAdapter productAdapter) {
            super(itemView);
            this.productAdapter = productAdapter;
            productName = itemView.findViewById(R.id.productNameItem);
        }
    }
}
