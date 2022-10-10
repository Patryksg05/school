console.log("hello world!");

// let age: number = 29; // przypisanie wartosci do typu numerycznego (sam to robi)
// DEKLARACJA TYPU ZMIENNEJ => TYPE INFERENCE
// let ageAsString: string = "..... world!";
// ageAsString = 'hello .....!'; // to samo
// ageAsString = `${age}`; 
// console.log(ageAsString)

// const add = (v1: number, v2: number) => v1 + v2;
// console.log(typeof(add(10,10)));

// const input1: HTMLInputElement = document.querySelector("#input1");
// const input2: HTMLInputElement = document.querySelector("#input2");
// const addButtonElement = document.querySelector("button");

// const add = (v1, v2) => parseInt(v1) + parseInt(v2);
// const add = (v1: number, v2: number) => v1 + v2;

// addButtonElement.addEventListener("click", ()=>{
    // const sum = add(parseInt(input1.value), Number(input2.value));
    // console.log(sum);
// })

// LITERAL TYPE
// const age = 29;

// operowanie kilka typow zmiennych => UNION TYPE
// const logAge = (age:number | string) =>{ 
    // console.log(`Mam ${age} lat`);
// 

// logAge(typeof(17));
// logAge(typeof("17"));


// let test: string | number | boolean;

// test = true;
// test = 12;
// test= "typeScript";

// TYP BOOLEAN

const btn = document.querySelector("button");

const calculatePrice = (orginalPrice: number, hasDiscount: boolean) => {
    return hasDiscount?orginalPrice*0.8: orginalPrice;
}

btn.addEventListener("click", ()=>{
    const orginalPrice: number = 50;
    // pobieramy wartosci (zwraca string) z url => 
    // http://127.0.0.1:5500/firstProject/index.html?discount=true
    const hasDiscount: boolean = new URLSearchParams(window.location.search
        ).get("discount") === "true";
    console.log(calculatePrice(orginalPrice, hasDiscount))
})

// TYP ARRAY

// deklaracja tablicy => variable: typ[]
// const tasks: string[] = ["wyrzucic smieci", "pouczyc sie", "coding..."]
// tasks.push(10); blad!

// tworzenie tablicy obiektow

// klamry => to co chcemy zaimportowac
import {Task, Category} from "./types/types"

// OPTIONAL PROPERTY
const categories: Category[] = ["general", "work", "sport", "hobby"];

// let text: "movie"; === LITERAL TYPE

const tasks: Task[] = [
{
    title: "Wyrzucic smieci", 
    done: false,
    // category: "general"
}, {
    title: "nauka", 
    done: false,
    category: "work"
}, {
    title: "coding", 
    done: true,
    category: "hobby"
    // category: "work"
}   
];

const categoriesContainerElement: HTMLElement = document.querySelector(".categories");

const renderCategories = () => {
    categories.forEach(category => {
        const categoryElement: HTMLElement = document.createElement("li");

        const radioInputElement: HTMLInputElement = 
            document.createElement("input");
            radioInputElement.type= "radio";
            radioInputElement.name = "category";
            radioInputElement.value = category;
            radioInputElement.id = `category - ${category}`

        categoryElement.appendChild(radioInputElement);

        const labelElement: HTMLLabelElement = document.createElement("label");
        labelElement.setAttribute("for", `category-${category}`)
        labelElement.innerHTML = category

        categoryElement.append(labelElement)

        categoriesContainerElement.appendChild(categoryElement);
    })
}

const taskContainerElement: HTMLElement = document.querySelector(".tasks");
const taskNameInputElement: HTMLInputElement = document.querySelector("#name");
const addButtonElement: HTMLButtonElement = document.querySelectorAll("button")[1];



const addTask = (task: Task) => {
    tasks.push(task);
}

addButtonElement.addEventListener("click", (event: Event)=>{
    const selectRadioElement: HTMLInputElement = document.querySelector(
        "input[type='radio']:checked"
    )
    // as type casting
    const selectedCategory: Category = selectRadioElement.value as Category;
    event.preventDefault();
   addTask({title: taskNameInputElement.value, done: false, category: selectedCategory})
   render(tasks, taskContainerElement);
})

addTask({title: "specjalne zadanie od szefuncia", done: true, category: "hobby"})
renderCategories()
render(tasks, taskContainerElement);

const displayArray = () => {
    tasks.forEach(task => {
        console.log(task)
    })
}

displayArray()

