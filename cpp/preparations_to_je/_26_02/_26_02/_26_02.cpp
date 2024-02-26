#include <iostream>

#define SIZE 50

using namespace std;

/*********************************
    nazwa funkcji: fillArray
    parametry wejściowe: tablica 
    wartosc zwracana: tablica 50 elementowa z wylosowanymi elementami
    infomacje: funkcja wypełnia tablice 50 elementowa wartościami
        pseudolosowymi z zakresu od 1 do 100    
    autor: Maciak Patryk        
*********************************/
int* fillArray(int* tab)
{
    tab = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        tab[i] = rand() % 100 + 1;
    return tab;
}
/*********************************
    nazwa funkcji: sentry
    parametry wejściowe: tablica, zmienna typu liczbowego
    wartosc zwracana: true/false jezeli wartonik jest odnaleziony
    infomacje: wypelniona tablica 50 elementowa wartosciami od 1 do 100
        jest przeszukiwana w petli, jezeli wartosc - n, jest rowna i
        elementowi w tablicy oraz i jest rozne od wartosci ostatniego 
        elementu tablicy zwracamy ze wartownik zostal odnaleziony i przerywamy
        iteracje, w przeciwnym razie zwracamy true ze nasza szukana wartosc
        n - wartownik jest odnaleziony na samym koncu tablicy.
    autor: Maciak Patryk
*********************************/
bool sentry(int tab[SIZE], int n)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (tab[i] == n && i != SIZE - 1)
        {
            return false;
            break;
        }
    }
    return true;
}
/*********************************
    nazwa funkcji: 
    parametry wejściowe: tablica, zmienna typu liczbowego
    wartosc zwraca: index wpisanego elemntu
    infomacje: funkcja przeszukuje tablice oraz zwraca index
        wyszukanego elementu (zmienna: element), jezeli
        element jest w tablicy zwracamy go oraz przerywami iteracje, 
        w przeciwnym razie gdy go nie znajdziemy zwracamy -1
    autor: Maciak Patryk
*********************************/
int returnIndex(int tab[SIZE], int element)
{
    for (int i = 0; i < SIZE; i++)
        if (tab[i] == element)
        {
            return i;
            break;
        }
    return -1;
}

int main()
{
    srand(time(NULL));    

    int* tab = new int[SIZE];
    tab = fillArray(tab);

	int x;
	cout << "Wpisz wyszukiwana wartosc: "; cin >> x;
	tab[SIZE - 1] = x;

	for (int i = 0; i < SIZE; i++)
		cout << tab[i] << ", ";

    sentry(tab, x) ? cout << endl << x << " = sentry" : cout << endl << "at index: " << returnIndex(tab, x);
}

