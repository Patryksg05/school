console.log('kartkowka => Maciak Patryk')
// TABLICE: 

let tablica1 = [2,3,4,5,6,7,11,6,12,12]
console.log('5 element: ' + tablica1[4])

let tablica2 = []
tablica2 = tablica2.concat(tablica1)

let tablica3 = []
for(let i=0; i<tablica1.length; i++)
{
    tablica3[i] = tablica1[i] + tablica2[i]
}

tablica2 = reverseArray(tablica1)
// console.log(tablica2)

console.log(tablica1)
console.log('Min element: ' + min_value(tablica1))
console.log('Max element: ' + max_value(tablica1))
console.log('Average: ' + average(tablica1))
console.log('3: ' + threeInArray(tablica1))
console.log('Rosnaco: ' + ascendingSort(tablica1))

function ascendingSort(Array)
{
    let temp;
    for(let i=0; i<Array.length-1; i++)
    {
        let minIndex = i
        for(let j = i+1; j<Array.length; j++)
            if(Array[j] < Array[minIndex]) 
                minIndex = j
        let temp = Array[minIndex]
        Array[minIndex] = Array[i]
        Array[i] = temp
    }
    return Array;          
}

function threeInArray(Array)
{
    let threeArray = []
    for(let i=0; i<Array.length; i++)
    {
        if(Array[i] == 3)
            threeArray.push(Array[i])
    }
    return threeArray.length
}

function average(Array)
{
    let sum = 0
    for(let i=0; i<Array.length; i++)
        sum+=Array[i]
    return sum/Array.length
}

function min_value(Array)
{
    let min_value = Array[0]
    for(let i=0; i<Array.length; i++)
    {
        if(min_value>Array[i])
            min_value = Array[i]
    }
    return min_value
}

function max_value(Array)
{
    let max_value  = Array[0]
    for(let i=0; i<Array.length; i++)
    {
        if(max_value<Array[i])
            max_value = Array[i]
    }
    return max_value
}

function reverseArray(Array)
{   
    let output = []
    for(let i=Array.length-1; i>=0; i--)
    {
        output.push(Array[i])
    }
    return output
}