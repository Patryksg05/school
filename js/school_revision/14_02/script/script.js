/**
    * Utwórz tablicę o nazwie tab1, zawierającą następujące liczby całkowite: 7, 3, 1, 6, 9, 5, 4, 10, 2, 2.
    Wypisz zawartość 5 komórki tablicy na ekran. Zmień zawartość 7 komórki tablicy, wprowadzając do niej wartość 12.
    Utwórz drugą tablicę o nazwie tab2, o tej samej wielkości co tab1. Przepisz zawartość tab1 do tab2.
    Utwórz trzecią tablicę o nazwie tab3, o tej samej wielkości co dwie poprzednie. 
    Zawartością komórek tablicy tab3 jest suma komórek o tych samych indeksach tablic tab1 i tab2.
    Przepisz ponownie zawartość tablicy tab1 do tablicy tab2, jednak w odwrotnej kolejności.
 */


let myArray = [7,3,1,6,9,5,4,10,2,2]
// console.log("tab1: " + myArray)
// console.log("tab[4]: " + myArray[4] + "\nprzed zamiana: " + myArray[6])
myArray[6] = 12
// console.log("po zamianie: " + myArray[6])

// let tab2 = []
// Array.prototype.push.apply(tab2, myArray)
// console.log(tab2.length)

let tab2 = []
tab2 = tab2.concat(myArray)
// console.log("tab1: " + myArray)
// console.log("tab2: " + tab2)

let tab3 = []
// tab3 = myArray.concat(tab2)
// console.log("tab3: " + tab3)

let sum = 0;
for(let i=0; i<myArray.length; i++)
{
    sum = myArray[i] + tab2[i];
    tab3.push(sum)
}

// console.log("tab3: " + tab3)

// tab2 = myArray.reverse()
// console.log(tab2)

function reverseArray(Array)
{
    let output = []
    for(let i=Array.length-1; i>=0; i--)
        output.push(Array[i])

    return output    
}

tab2 = reverseArray(myArray)
// console.log("tab2 po zamianie: " + tab2)
    
let tab =[667,3,78,9]
// let num
// for(let i=0; i<3; i++)
    // tab.push(num = prompt())
/*
console.log("tab od user: " + tab)
console.log("min element: " + min_value(tab))
console.log("max element: " + max_value(tab))
console.log("srednia wartosc: " + average(tab))
console.log("wystapien 3: " + howManyThree(tab))
console.log("sortowanie malejace: " + ascendingSort(tab))
console.log("sortowanie rosnace: " + descendingSort(tab))
console.log("mediana: " + median(tab))
console.log("max 3 elementy: " + maxThreeElements(tab))
console.log("min 3 elementy: " + minThreeElements(tab))
console.log("liczby parzyste w tablicy: " + evenNumbers(tab))
console.log("liczby nie parzyste w tablicy: " + oddNumbers(tab))
console.log("podzielne przez 3: " + divideByThree(tab))
// console.log("do kwadratu: " + squareOfNumber(tab))
 */

// Oblicz średnią wartość elementów tablicy.
function average(Array)
{
    let sum = 0, average = 1;
    for(let i=0; i<Array.length; i++)
        sum += Array[i]
    average = sum/Array.length
    return average
}

// Wypisz 3 najmniejsze i trzy największe elementy tablicy.
function maxThreeElements(Array)
{
    let maxElements = [];
    descendingSort(Array);
    maxElements.push(Array[Array.length-1])
    maxElements.push(Array[Array.length-2])
    maxElements.push(Array[Array.length-3])
    return maxElements
}

// Wypisz 3 najmniejsze i trzy największe elementy tablicy.
function minThreeElements(Array)
{
    let mixElements = [];
    ascendingSort(Array);
    mixElements.push(Array[Array.length-1])
    mixElements.push(Array[Array.length-2])
    mixElements.push(Array[Array.length-3])
    return mixElements
}

// Policz ilość liczb parzystych i nieparzystych w tablicy.
function evenNumbers(Array)
{
    let evenNumbers = []
    for(let i=0; i<Array.length; i++)
        if(Array[i]%2==0)
            evenNumbers.push(Array[i])
    return evenNumbers                
}

// Policz ilość liczb parzystych i nieparzystych w tablicy.
function oddNumbers(Array)
{
    let oddNumbers = []
    for(let i=0; i<Array.length; i++)
        if(Array[i]%2!=0)
            oddNumbers.push(Array[i])
    return oddNumbers                
}

// Podaj ile liczb zawartych w tablicy jest podzielna bez reszty przez 3.
function divideByThree(Array)
{
    let dividers = []
    for(let i=0; i<Array.length; i++)
        if(Array[i]%3==0)
            dividers.push(Array[i])
    return dividers.length        
}

// Dowolnym sposobem posortuj elementy tablicy w porządku rosnącym.
function descendingSort(Array)
{
    let temp;
    for(let i=0; i<Array.length-1; i++)
    {
        let minIndex = i
        // looking for min element
        for(let j = i+1; j<Array.length; j++)
            if(Array[j] < Array[minIndex]) 
                minIndex = j
        let temp = Array[minIndex]
        Array[minIndex] = Array[i]
        Array[i] = temp
    }
    return Array;          
}

// Dowolnym sposobem posortuj elementy tablicy w porządku rosnącym.
function ascendingSort(Array)
{
    let temp;
    for(let i=0; i<Array.length-1; i++)
    {
        let minIndex = i
        // looking for min element
        for(let j = i+1; j<Array.length; j++)
            if(Array[j] > Array[minIndex]) 
                minIndex = j
        let temp = Array[minIndex]
        Array[minIndex] = Array[i]
        Array[i] = temp
    }
    return Array;          
}

// Zwiększ wartość każdego elementu tablicy podnosząc go do kwadratu.
function squareOfNumber(Array)
{
    for(let i=0; i<Array.length; i++)
        Array[i] = Array[i]**2
    return Array
}

// Znajdź medianę elementów tablicy.
function median(Array)
{
    if(Array.length === 0) console.log("no numbers!")

    ascendingSort(Array)
    let half = Math.floor(Array.length/2)
    if(Array.length%2)
        return Array[half]

    return (Array[half-1] + Array[half])/2.0
}

// Wylicz ilość wystąpień cyfry 3 w tablicy.
function howManyThree(Array)
{
    let howManyThree = 0;
    for(let i=0; i<Array.length; i++)
        if(Array[i] == 3)
            howManyThree++
    return howManyThree        
}

// Znajdź najmniejszy i największy element w tablicy.
function min_value(Array)
{
    let mini_value = Array[0]
    for(let i=0; i<Array.length; i++)
        if(mini_value>Array[i])
            mini_value = Array[i]
    return mini_value
}

// Znajdź najmniejszy i największy element w tablicy.
function max_value(Array)
{
    let max_value = Array[0]
    for(let i=0; i<Array.length; i++)
        if(max_value<Array[i])
            max_value = Array[i]
    return max_value
}

// ZADANIE 3 (tablice)

/**
 * Wypełnij ją literami wprowadzonymi przez użytkownika
let tabChar = []
let charElement
while (1) {
    if((charElement = prompt()) && charElement.length == 1)
        tabChar.push(charElement)
    else
        alert("tylko jedna litera!")
    
    if(tabChar.length == 10)
        break;
}
console.log(tabChar)

 * Wypełnij ją 10 literowym wyrazem podanym przez użytkownika.
let tabChar = []
let charElement
while (1) {
    if((charElement = prompt()) && charElement.length == 10)
        tabChar.push(charElement)
    else
        alert("tylko jedna litera!")
    
    if(tabChar.length == 10)
        break;
}
console.log(tabChar)

// Zamień wszystkie wielkie litery na małe i odwrotnie.
let tabChar = []
let charElement
while (1) {
    if((charElement = prompt()) && charElement.length == 1)
    {
        if(charElement == charElement.toUpperCase())
            charElement = charElement.toLowerCase()
        else
            charElement = charElement.toUpperCase()
        tabChar.push(charElement)
    }
    else
        alert("tylko jedna litera!")
    
    if(tabChar.length == 2)
        break;
}
console.log(tabChar) // ?? Wypisz zawartość tablicy w losowej kolejności.

 */

let randomTab = Array(100).fill().map(() => 100* Math.random())
for(let i=0; i<randomTab.length; i++)
    randomTab[i] = Math.floor(randomTab[i])

console.log(descendingSort(randomTab))
console.log("max element: " + max_value(randomTab) + " wystapila: " + findMaxAndHowManyIsInTheArray(randomTab))
console.log("liczby nieparzyste: " + oddNumbers(randomTab)) // Wyświetl na ekran liczby nieparzyste.
console.log("liczby o nieparzystym indexie: " + oddIndex(randomTab))
console.log("liczby z przedzialu <5,15): " + numberBetween5And15(randomTab) + " ile?=" + numberBetween5And15(randomTab).length)
console.log("Poprzednik/nasteonik min elementu: " + previousAndNextMiniElement(randomTab))

// Znajdź największą spośród liczb oraz wyświetl na ekranie 
// informację mówiącą o tym, ile razy ta liczba znalazła się w tablicy.
function findMaxAndHowManyIsInTheArray(Array)
{
    let maxi = max_value(Array)
    let howMany = 0
    for(let i=0; i<Array.length; i++)
        if(Array[i] === maxi)
            howMany++

    return howMany
}

// Wyświetl na ekran liczby znajdujące się w komórkach o nieparzystych indeksach.
function oddIndex(Array)
{
    let oddNumbersFromIndex = []
    for(let i=0; i<Array.length; i++)
        if(i%2!=0)
            oddNumbersFromIndex.push(Array[i])
    return oddNumbersFromIndex 
}

// Program policzy ile liczb zawiera się w przedziale <5, 15) , po czym wypisze te liczby na ekran.
function numberBetween5And15(Array)
{
    let numbers = []
    for(let i=0; i<Array.length; i++)
    {
        if(Array[i]>=5 && Array[i]<15)
            numbers.push(Array[i])
    }
    return numbers
}

// zadanie 5??

// Znajdź poprzednik i następnik najmniejszej wartości w tablicy 
// (wartość komórki o numerze o jeden większym i o jeden mniejszym, niż indeks minimum tablicy).
function previousAndNextMiniElement(Array)
{
    let previousAndNext = []
    let mini_value = Array[0], previous, next
    for(let i=0; i<Array.length; i++)
    {
        if(mini_value>Array[i])
            mini_value = Array[i]
    }
    // previousAndNext.push(previous)
    previousAndNext.push(Array[Array[mini_value]+1])
    previousAndNext.push(Array[Array.length-1])
    return previousAndNext;
}

/**
    Przepisać do nowej tablicy te elementy, których wartość jest >10. 
    Nowa tablica ma mieć rozmiar równy ilości tych elementów.
let moreThanTen = []
for(let i=0; i<randomTab.length; i++)
{
    if(randomTab[i] > 10)
        moreThanTen.push(randomTab[i])
}

moreThanTen.length = moreThanTen.length
console.log("tab>10: " + moreThanTen)
 */

let tab4 = []

for(let i=0; i<100; i++)
{
    for(let j=0; j<randomTab.length; j++)
        tab4[i] = randomTab[j] + randomTab[i]   
}

// console.log(tab4)

// console.log("posortowana malejaco: " + ascendingSort(randomTab))
console.log(randomTab)
