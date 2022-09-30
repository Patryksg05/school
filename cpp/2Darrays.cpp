#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// content 'randomNumberArray2D': filling array from random numbers
// content 'guessTheNumber': guess the appropriate number from random numbers

void randomNumberArray2D(){
    int row, column, range;
    cout << "Wiersze = "; cin >> row;
    cout << "Kolumny = "; cin >> column;
    int tab[row][column];
    cout << "Zakres licz losowych = "; cin >> range;
    cout << "Wynik: \n";
    srand(time(NULL));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            tab[i][j] = rand()%range;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void guessTheNumber(){
    int randomNumber = (rand()%100)+1; // from 0 to 100
    bool wasNumberGuessed = false;
    int userNumber;

    while(!wasNumberGuessed){
        cout << "\n\nEnter a number: "; cin >> userNumber;
        if(userNumber>randomNumber)
            cout << "Numer is to high!";
        else if(userNumber<randomNumber)
            cout << "Number is to low!";
        else{
            cout << "Congratulations! This number was = " << randomNumber;
            wasNumberGuessed = true;
        }
    }
}

int main()
{
    randomNumberArray2D();
    guessTheNumber();
    return 0;
}
