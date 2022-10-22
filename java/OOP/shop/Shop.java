import java.nio.channels.SelectableChannel;
import java.util.ArrayList;

public class Shop {

    private static Shop shop = new Shop();
    private ArrayList<Customer> customers = new ArrayList<Customer>();
    private ArrayList<Product> products = new ArrayList<Product>();
    private ArrayList<Seller> sellers = new ArrayList<Seller>();

    public Shop() {
    }

    public static Shop getShop() {
        return shop;
    }

    private boolean isCustomerInShop(Customer customer) {
        return customers.contains(customer);
    }

    public void addCustomerToShop(Customer customer) {
        if(!isCustomerInShop(customer))
            customers.add(customer);
        else
            System.out.println("Customer: "+customer.getLastName()+" is already in the shop!\n");
    }

    private boolean isProductInShop(Product product) {
        return products.contains(product);
    }

    public void addProductToShop(Product product) {
        if(!isProductInShop(product))
            products.add(product);
        else
            System.out.println("Product: "+product.getNameOfProduct()+" is already in the shop!\n");
    }

    private boolean isProductAvialable(Product product) {
        if(products.contains(product))
            return product.isAvailable();
        else
            return false;
    }

    public void addProductToCustomer(Customer customer, String name) {
        for(Product product: products) {
            if(product.getNameOfProduct().equals(name) && isProductAvialable(product)) {
                product.setAvailable(false);
                customer.addProductToCustomer(product);
//                int sizeOfCustomerProducts = customer.getCustomerProducts().size();
                howManyProductsHaveCustomer(customer.getLastName());
                totalBill(customer);
            }
        }
    }

    private void howManyProductsHaveCustomer(String lastName) {
        for(Customer customer: customers) {
            if(customer.getLastName().equals(lastName)) {
                customer.setCountOfProducts(customer.getCustomerProducts().size());
            }
        }
    }

    private void totalBill(Customer customer) {
        int sum = 0;
        for(Product product: products) {
            if(customer.getCustomerProducts().contains(product)) {
                if(hasCustomerDiscount(customer)) {
                    sum += (product.getPrice()) - (product.getPrice()*0.5);
                }
                else if (hasGoldenCard(customer)) {
                    sum += (product.getPrice()) - (product.getPrice()*0.8);
                }
                else
                    sum += product.getPrice();
            }
        }
        customer.setTotalBill(sum);
    }

    private boolean hasCustomerDiscount(Customer customer) {
        for(Product product: products) {
            if(customer.getCustomerProducts().contains(product)) {
                if(customer.getCustomerProducts().size()>=5) {
                    customer.setHasDiscount(true);
                    return true;
                }
            }
        }
        return false;
    }

    private boolean hasGoldenCard(Customer customer) {
        for(Product product: products) {
            if(customer.getCustomerProducts().contains(product)) {
                if(customer.getCustomerProducts().size()>=10) {
                    customer.setHasGoldenCard(true);
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isSellerInShop(Seller seller) {
        return sellers.contains(seller);
    }

    public void addSelerToShop(Seller seller) {
        if(!isSellerInShop(seller))
            sellers.add(seller);
        else
            System.out.println("Seller: "+seller.getLastName()+" is already in the shop!\n");

    }

    @Override
    public String toString() {
        return "Shop {" +
                "\ncustomers=" + customers +
                "\nproducts=" + products +
                "\nselers= " + sellers +
                "} ";
    }
}
