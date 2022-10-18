/**
 * npm i -g typescript
 * tsc && node *.js
 */

console.log("\nkartkowka MaciakPatryk\n");

abstract class Animal {
    private name: string;
    private age: number;
    private weigh: number;
    private hunger: number;

    constructor(name: string, age: number, weigh: number, hunger: number) {
        this.name = name;
        this.age = age;
        this.weigh = weigh;
        this.hunger = hunger;
    }

    public get _name(): string{
        return this.name;
    }

    public set _name(name: string){
        this.name = name;
    }

    public get _age(): number{
        return this.age;
    }

    public set _age(age: number){
        this.age = age;
    }

    public get _hunger(): number{
        return this.hunger;
    }

    public eat(): void {
        this.hunger -= 10;
    }

    public action(): void {
        this.hunger += 5;
    }

}

class Mammal extends Animal {
    private happy: number;

    constructor(name: string, age: number, weigh: number, hunger: number, happy: number) {
        super(name, age, weigh, hunger);
        this.happy = happy;
    }

    public get _happy(): number{
        return this.happy;
    }

    public game(): void {
        this.happy += 10;
    }

    public toString(): void {
        console.log(`
            name = ${this._name}\n
            age = ${this._age}\n
            hunger = ${this._hunger}\n
            happy = ${this._happy}
        `)  
    }
}

const mammal1: Mammal = new Mammal("Tyranozuar", 101, 105, 50, 100);
mammal1.eat();
console.log('After eating: ' + mammal1._hunger);
mammal1.action();
console.log('After action: ' + mammal1._hunger);
mammal1.game();
console.log('After (first) game: ' + mammal1._happy);
mammal1.game();
console.log('After (second) game: ' + mammal1._happy);

mammal1.toString();