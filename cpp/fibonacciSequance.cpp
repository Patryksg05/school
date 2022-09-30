#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define N 10000 // liczba elementow tablicy

void ciagFibonacciego(double tab[N]){
    int n;
    cout << "\nIle liczb ciagu Fibonacciego wyznaczyc?\n";
    cout << "Liczba wyznaczajaca ciag = "; cin >> n;
    tab[0] = 1;
    tab[1] = 1;
    for(int i=2;i<n;i++)
        tab[i] = tab[i-1] + tab[i-2];

    cout << setprecision(1000);

    for(int i=0; i<n; i++)
        cout << "\nLiczba nr: " << i+1<< " = " << tab[i] << "\n";

    cout << "\nOstatni element = " << tab[n-1];
    // zlota liczba
    cout << "\nZlota liczba = " << setprecision(3) << tab[n-1]/tab[n-2];
}

int main()
{
    double tab[N];
    int length = sizeof(tab)/sizeof(tab[0]);
    cout << "Liczba elementow tablicy = " << length;
    ciagFibonacciego(tab);
    return 0;
}
