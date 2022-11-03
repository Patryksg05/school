// name of class => first letter to upper!

/*
    1. npm install -g typescript
    2. npx tsc .. .ts
    3. node ... .js
*/

class House{
    owner: string;

    constructor(owner: string){
        this.owner = owner;
    }

    changeOwner(owner: string): void{
        this.owner = owner;
    }

    getOwner(): string{
        return this.owner;
    }
}

const house: House = new House("BOSS");
house.changeOwner("Patryk");
console.log(house);


abstract class Restaurant{
    readonly name: string;
    private pizzaInOrder: string[] = [];
    private maxPizzaInOwen: number = 10;
    protected recipies: string[] = [];
    private static id: number = 1;
    id:number;
    private _manager: string;
    /* 
        - podkreslniki dodajemy przy nazwie pola
            zeby get i set moglo miec nazwe normalna
    */

    constructor(name: string){
        this.name = name;
        this.id = Restaurant.id++;
    }

    getRestaurantName(): void{
        console.log(`\nWELCOME IN: ${this.name} { ${this.id} } pizza`)
    }

    get manager(){
        return this._manager;
    }

    set manager(manager){
        this._manager = manager; 
    }

    public order(pizza:string){
        this.pizzaInOrder.push(pizza);
        console.log("Orders: ")
        this.pizzaInOrder.forEach(piz =>{
            console.log(`- ${piz}`);
        });
    }

    private isOvenFull(): boolean{
        return this.pizzaInOrder.length >
            this.maxPizzaInOwen;
    }

    abstract bake();

}

class PolishRestaurant extends Restaurant{
    private _street: string;
    constructor(name: string, street: string){
        super(name);
        this._street = street;
    }

    get street(){return this._street}

    bake() {
        return `The pizza is baking by the polish tradition!`;
    }
}


// const restaurant: Restaurant = new Restaurant("uWuja");
// restaurant.getRestaurantName();
// restaurant.order("hawajska");


// const restaurant2: Restaurant = new Restaurant("uPatryka");
// restaurant2.getRestaurantName();
// restaurant2.order("margharita")
// restaurant.manager("");
// console.log(restaurant.manager);

const polishRestaurant:PolishRestaurant = new PolishRestaurant("uWUja", "Janika");
polishRestaurant.getRestaurantName();
console.log(polishRestaurant.street)
polishRestaurant.order('hawajska');
console.log(polishRestaurant.bake());



