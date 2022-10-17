// klasy: person(abstract), clients(extends)

abstract class Person {
    private firstName: String;
    private lastName: String;
    private birthdayDate: string;

    constructor(firstName: string, lastName: string, birthdayDate: string) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.birthdayDate = birthdayDate;
    }

    public get _firstName(): String{
        return this.firstName;
    }

    public get _lastName(): String{
        return this.lastName;
    }

    public get _birthdayDate(): String{
        return this.birthdayDate;
    }
}

class Customer extends Person {
    private customerPizza: Pizza[] = [];
    private static countOfCustomer: number = 1;
    countOfCustomer: number;
    private idCustomer: number;
    private bill: number;

    constructor(firstName: string, lastName: string, birthdayDate: string) {
        super(firstName, lastName, birthdayDate);
        this.idCustomer = Customer.countOfCustomer;
    }

    public get _idCustomer(): number{
        return this.idCustomer;
    }

    public get _customerPizza() {
        return this.customerPizza;
    }

    public addPizzaToCustomer(pizza: Pizza) {
        this.customerPizza.push(pizza);
    }

    public get _bill(): number{
        return this.bill;
    }

    public set _setBill(bill: number){
        this.bill = bill;
    }

}

class Pizza {
    private name: String;
    private price: number;
    private isOrder: boolean;

    constructor(name: String, price: number, isOrder: boolean) {
        this.name = name;
        this.price = price;
        this.isOrder = isOrder;
    }

    public get _pizzaName(): String{
        return this.name;
    }

    public get _pizzaPrice(): number{
        return this.price;
    }

    public get _isOrder(): boolean{
        return this.isOrder;
    }

    public set _setOrder(isOrder: boolean){
        this.isOrder = isOrder;
    }
}

class Restaurant {

    private static restaurant: Restaurant = new Restaurant();

    private customers: Array<Customer> = new Array<Customer>;
    private pizzas: Pizza[] = [];

    public Restaurant(){

    }

    public addPizzaToRestaurant(pizza: Pizza): void {
        this.pizzas.push(pizza);
    }

    private isPizzaAvaiable(pizza: Pizza): boolean {
        for(let i: number = 0; i<this.pizzas.length; i++) {
            if(this.pizzas[i] == pizza) {
                return pizza._isOrder;
            }
            else
                return false;
        }
    }

    public isCustomerInRestaurant(customer: Customer): boolean {
        for(let i:number = 0; i<this.customers.length; i++) {
            if(this.customers[i] == customer) {
                return true;
            }
            else
                return false;
        }
    }
    
    public addCustomerToRestaurant(customer: Customer): void {
        if(!restaurant1.isCustomerInRestaurant(customer))
            this.customers.push(customer);
        else
            console.log(`${customer._lastName} is in the restaurant already!`)
    }

    public addPizzaToCustomer(customer: Customer, nameOfPizza: String) {
        this.pizzas.forEach(function (pizza: Pizza){
            if(nameOfPizza == pizza._pizzaName && !restaurant1.isPizzaAvaiable(pizza)) {
                pizza._setOrder = true;
                customer.addPizzaToCustomer(pizza);
                restaurant1.countBill(customer);
            }
        }) 
    }

    private countBill(customer: Customer) {
        let sum: number = 0;
        customer._customerPizza.forEach(function (pizza:Pizza){
            sum += pizza._pizzaPrice;
        })
        customer._setBill = sum;
    }

    public toString(): void {
        console.log(this.customers);
        console.log(this.pizzas);
    }
}


const pizza1: Pizza = new Pizza("Margharita", 100, false);
const pizza2: Pizza = new Pizza("Hawajska", 56, false);

pizza1.toString();

const customer1: Customer = new Customer("Jack", "Davidson", "1978.05.10");
// const customer2: Customer = new Customer("Jack", "Davidson", "1978.05.10");

const restaurant1: Restaurant = new Restaurant();

restaurant1.addCustomerToRestaurant(customer1);
// restaurant1.addCustomerToRestaurant(customer1); return false

restaurant1.addPizzaToRestaurant(pizza1)
restaurant1.addPizzaToRestaurant(pizza2)

restaurant1.addPizzaToCustomer(customer1, "Margharita");
restaurant1.addPizzaToCustomer(customer1, "Hawajska");

// restaurant1.addPizzaToCustomer(customer1, "Margharita"); returl false

restaurant1.toString();

