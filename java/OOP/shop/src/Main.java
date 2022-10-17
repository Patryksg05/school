import com.sun.security.jgss.GSSUtil;

public class Main {
    public static void main(String[] args) {
        System.out.println("SHOP PROJECT in java => (OOP) <=\n");

        Customer customer1 = new Customer("Jack", "Smith", "1980.05.10");
        Customer customer2 = new Customer("Centrall", "Cee", "1999.02.12");

        Seller seller1 = new Seller("Micheal", "Levis II", "1987.05.30", "2000.01.01", 10000);

        Product product1 = new Product("Lays", 100, true);
        Product product2 = new Product("Pizza", 867, true);

        Shop shop = new Shop();

//        System.out.println(customer1);
//        System.out.println(seller1);
//        System.out.println(product1);

        shop.addCustomerToShop(customer1);
        shop.addCustomerToShop(customer2);

        shop.addSelerToShop(seller1);

        shop.addProductToShop(product1);
        shop.addProductToShop(product2);

        shop.addProductToCustomer(customer1, "Lays");
        shop.addProductToCustomer(customer1, "Pizza");

        System.out.println(shop);
    }
}
