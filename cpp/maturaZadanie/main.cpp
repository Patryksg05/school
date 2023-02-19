#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

// 1. Ile spośród liczb zapisanych w pliku dane.txt spełnia taki warunek, że pierwsza cyfra
// tej liczby jest równa ostatniej cyfrze tej samej liczby?
// 2. Podaj, ile liczb w pliku dane.txt, po ich zapisaniu w systemie dziesiętnym, spełnia
// podpunkcie a), tzn. pierwsza cyfra liczby jest równa ostatniej cyfrze tej samej liczby.
// 3. Ile spośród liczb zapisanych w pliku dane.txt spełnia warunek, że rozpoczynając od
// najbardziej znaczącej cyfry w zapisie ósemkowym, każda kolejna cyfra tej liczby nie jest
// mniejsza od cyfry poprzedzającej? Podaj największą i najmniejszą liczbę z pliku
// dane.txt, które spełniają ten warunek
// Liczba 123357 spełnia podany warunek, ponieważ 1≤2≤3≤3≤5≤7.

int osemkowy_na_dziesietny(string osemkowa)
{
    int dziesietna = strtol(osemkowa.c_str(), NULL, 8);
    return dziesietna;
}

bool isRacing(string n)
{
    bool isRacing = true;
    for(int i=0; i<n.size()-1; i++)
    {
        if(n[i]>n[i+1])
        {
            isRacing = false;
            break;
        }
    }
    return isRacing;
}

int main()
{
    cout << "Zadanie 6.a\n";

    fstream file1, file2, file3;
    file1.open("dane.txt");

    string line;
    int firstElement, lastElement, firstEqualLast = 0;

    for(int i=0; i<20; i++)
    {
        getline(file1, line);
        firstElement = line[0];
        lastElement = line[line.size()-1];
        cout << line << " " << line[0] << " " << line[line.size()-1] << endl;

        if(firstElement == lastElement)
            firstEqualLast++;
    }

    cout << "Pierwsza rowna ostatniej = " << firstEqualLast;

    file1.close();

    cout << "\n\nZadanie 6.b\n";

    file2.open("dane.txt");
    string octal, decimalString;
    int decimal, firstEqualLastDecimal;

    for(int i=0; i<50; i++)
    {
        getline(file2, octal);
        decimal = osemkowy_na_dziesietny(octal);
        decimalString = to_string(decimal);

        cout << octal << " " << decimalString << " " << decimalString[0] << " "
            << decimalString[decimalString.size()-1] << endl;

        if(decimalString[0] == decimalString[decimalString.size()-1])
            firstEqualLastDecimal++;
    }

    cout << "Pierwsza rowna ostatniej (10) = " << firstEqualLastDecimal;

    file2.close();

    cout << "\n\nZadanie 6.c\n";

    file3.open("dane.txt");
    int totalRiseSequences = 0, max_value;
    string line3;

    for(int i=0; i<3; i++)
    {
        max_value = line3[line3.size()-1];
        getline(file3, line3);
        cout << line3 << " " << isRacing(line3) << endl;
        if(isRacing(line3))
        {
            totalRiseSequences++;
        }
    }
    cout << "Laczna liczba ciagow rosnacych: " << totalRiseSequences;
    cout << endl << max_value;
    file3.close();

    return 0;
}
