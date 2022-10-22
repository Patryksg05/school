import java.util.ArrayList;

public class Customer extends Person{
    private ArrayList<Product> customerProducts = new ArrayList<Product>();
    private float totalBill;
    private boolean hasDiscount; // jezeli tablica jest wieksza niz 5 produktow dodajemy znikze 50% z rachunku
    private boolean hasGoldenCard; // jezeli tablica jest wieksza niz 10 elemntow odejmujemy cene 5 ostatnich elementow
    private int idCustomer;
    private static int countOfCustomers = 1;

    private int countOfProducts = 0;

    public Customer(String firstName, String lastName, String dateOfBirthdayDate) {
        super(firstName, lastName, dateOfBirthdayDate);
        this.idCustomer = countOfCustomers++;
    }

    public ArrayList<Product> getCustomerProducts() {
        return customerProducts;
    }

    public float getTotalBill() {
        return totalBill;
    }

    public boolean isHasDiscount() {
        return hasDiscount;
    }

    public boolean isHasGoldenCard() {
        return hasGoldenCard;
    }

    public int getIdCustomer() {
        return idCustomer;
    }

    public static int getCountOfCustomers() {
        return countOfCustomers;
    }

    public void setCustomerProducts(ArrayList<Product> customerProducts) {
        this.customerProducts = customerProducts;
    }

    public void setTotalBill(float totalBill) {
        this.totalBill = totalBill;
    }

    public void setHasDiscount(boolean hasDiscount) {
        this.hasDiscount = hasDiscount;
    }

    public void setHasGoldenCard(boolean hasGoldenCard) {
        this.hasGoldenCard = hasGoldenCard;
    }

    public void setIdCustomer(int idCustomer) {
        this.idCustomer = idCustomer;
    }

    public static void setCountOfCustomers(int countOfCustomers) {
        Customer.countOfCustomers = countOfCustomers;
    }
    public void addProductToCustomer(Product product) {
        this.customerProducts.add(product);
    }

    public void setCountOfProducts(int countOfProducts) {
        this.countOfProducts = countOfProducts;
    }

    public int getCountOfProducts() {
        return countOfProducts;
    }

    @Override
    public String toString() {
        return "Customer {" +
                "nameOfCustomer= " + getLastName() +
                "/totalBill=" + totalBill +
                "/hasDiscount=" + hasDiscount +
                "/hasGoldenCard=" + hasGoldenCard +
                "/idCustomer=" + idCustomer +
                "/countOfProducts= " + countOfProducts +
                "\n/customerProducts= " + customerProducts + "/\n" +
                '}';
    }
}
