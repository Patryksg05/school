#include <iostream>
#include <vector>

using namespace std;

// w -> wspolczynniki
int horner(vector<int> w, int stopien, int x)
{
    int wynik = w[0];
    for (int i = 1; i <= stopien; i++)
    {
        wynik = wynik * x + w[i];
    }
    return wynik;
}

int hornerRekurencyjnie(vector<int> w, int stopien, int x)
{
    if (stopien == 0)
        return w[0];
    return x * hornerRekurencyjnie(w, stopien - 1, x);
}

int main()
{
    cout << "SCHEMAT HORNERA\n";

    vector<int> wspolczynniki;
    wspolczynniki.push_back(1);
    wspolczynniki.push_back(3);
    wspolczynniki.push_back(-6);

    int stopien = 2;
    int x = 2;

    cout << "iteracyjnie: " << horner(wspolczynniki, stopien, x);
    cout << endl << 
        "rekurencyjnie1: " << hornerRekurencyjnie(wspolczynniki, stopien, x);
}
