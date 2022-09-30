#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

list <int> lista; // tworzymy liste o nazwie lista
int wybor;

void wyswietlanie()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout << "ZAWARTOSC LISTY: " << endl;
    cout << "-----------------------" << endl;
    for(list<int>::iterator i=lista.begin(); i!=lista.end(); ++i)
        cout << *i << " ";
    cout << endl;
    cout << "-----------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void push_fronT()
{
    int liczba;
    cout << "Podaj jaka liczbe wstawic na poczatek listy: ";
    cin >> liczba;
    Sleep(1500);
    lista.push_front(liczba);
}

void push_bacK()
{
    int liczba;
    cout << "Podaj jaka liczbe wstawic na koniec listy: ";
    cin >> liczba;
    Sleep(1500);
    lista.push_back(liczba);
}

void pop_fronT()
{
    cout << "Usuniecie pierwszego elementu listy";
    Sleep(1500);
    lista.pop_front();
}

void pop_bacK()
{
    cout << "Usuniecie ostatniego elementu listy";
    Sleep(1500);
    lista.pop_back();
}

void sizE()
{
    cout << "Liczba elementow listy: " << lista.size();
    Sleep(4000);
}

void maxSize()
{
    cout << "Max. liczba elementow listy: " << lista.max_size();
    Sleep(4000);
}

void emptY()
{
    cout << "Czy lista jest pusta ... ";
    if(lista.empty() == 1)
        cout << "PUSTA";
    else
        cout << "NIE PUSTA";
    Sleep(4000);
}

void removE()
{
    int liczba;
    cout << "Usun z listy WSZYSTKIE liczby rowne: "; cin >> liczba;
    Sleep(1500);
    lista.remove(liczba);
}

void sorT()
{
    cout << "Nastapi posortowanie (rosnaco) elementow listy ...";
    lista.sort();
    Sleep(2000);
}

void reversE()
{
    cout << "Nastapi odwrocenie elementow listy ...";
    lista.reverse();
    Sleep(2000);
}

void sumA()
{
    int suma = 0;
    for(list<int>::iterator i=lista.begin(); i!=lista.end(); ++i)
        suma+= *i;
    cout << "Suma elementow listy: " << suma;
    Sleep(2000);
}

void exit()
{
    cout << endl;
    cout << "KONIEC PROGRAMU!";
    exit(EXIT_FAILURE);
}

int main()
{
    do
    {
        wyswietlanie();
        cout << "MENU LISTY:" << endl;
        cout << endl << "1. push_front" << endl;
        cout << "2. push_back" << endl;
        cout << "3. pop_front" << endl;
        cout << "4. pop_back" << endl;
        cout << "5. size" << endl;
        cout << "6. maxSize" << endl;
        cout << "7. empty" << endl;
        cout << "8. remove" << endl;
        cout << "9. sort" << endl;
        cout << "10. reverse" << endl;
        cout << "11. suma" << endl;
        cout << "12. exit" << endl;
        cout << endl << "Twoj wybor: "; cin >> wybor;

        switch(wybor)
        {
        case 1: push_fronT(); break;
        case 2: push_bacK(); break;
        case 3: pop_fronT(); break;
        case 4: pop_bacK(); break;
        case 5: sizE(); break;
        case 6: maxSize(); break;
        case 7: emptY(); break;
        case 8: removE(); break;
        case 9: sorT(); break;
        case 10: reversE(); break;
        case 11: sumA(); break;
        case 12: exit(); break;

        default:
            cout << "Takiej liczby nie ma w naszym menu" << endl;
            cout << "Czy chcesz wrocic?" << endl;
            cout << "1 - TAK" << " 2 - NIE" << endl;
            Sleep(1000);
            cout << "Wybor: "; cin >> wybor;
            if(wybor == 1)
                Sleep(1000);
            else
                exit(EXIT_FAILURE);
            break;
        }
    }
    while(wybor>0 && wybor<12);
    return 0;
}
