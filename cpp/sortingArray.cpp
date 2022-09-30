#include <iostream>
#include <stdlib.h>

using namespace std;

// content: arkusze.pl/zawodowy/inf04-2022-styczen-egzamin-zawodowy-praktyczny.pdf

void createArray(int tab[], int length)
{
    for(int i=0; i<length; i++)
        tab[i] = rand()%100+1;
}

void displayArray(int tab[], int length)
{
    string result = "";
    for(int i=0; i<length; i++)
        result += to_string(tab[i])+ " ";

    cout << "Orginal array: [ "
        << result << "]";
}

int *sortArray(int tab[], int length)
{
    for(int i=0; i<length-1; i++)
    {
        if(tab[i]>tab[i+1])
        {
            int maxi = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = maxi;
            i = -1;
        }
    }
    return tab;
}

int maxiElement(int tab[], int length)
{
    int maxi;
    for(int i=0; i<length; i++)
    {
        if(maxi<tab[i])
            maxi = tab[i];
    }
    return maxi;
}

void displayInfomationAboutArray()
{
    int length = 10, tab[length];
    createArray(tab, length);
    displayArray(tab, length);

    int *tab1;
    tab1 = sortArray(tab, length);
    string result = "";
    for(int i=0; i<length; i++)
        result += to_string(tab1[i]) + " ";
    cout << "\nSorted array: [ "
        << result << "]";
    cout << "\nMax element: " << maxiElement(tab, length);
    delete [] tab1;
}

int main()
{
    displayInfomationAboutArray();
    return 0;
}
