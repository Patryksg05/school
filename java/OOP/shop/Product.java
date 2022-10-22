public class Product {
    private String nameOfProduct;
    private float price;
    private boolean isAvailable;

    public Product(String nameOfProduct, float price, boolean isAvailable) {
        this.nameOfProduct = nameOfProduct;
        this.price = price;
        this.isAvailable = isAvailable;
    }

    public String getNameOfProduct() {
        return nameOfProduct;
    }

    public float getPrice() {
        return price;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setNameOfProduct(String nameOfProduct) {
        this.nameOfProduct = nameOfProduct;
    }

    public void setPrice(float price) {
        this.price = price;
    }
    public void setAvailable(boolean available) {
        isAvailable = available;
    }

    @Override
    public String toString() {
        return "Product{" +
                "nameOfProduct='" + nameOfProduct + '\'' +
                "/price=" + price +
                "/isAvailable=" + isAvailable +
                '}';
    }
}
