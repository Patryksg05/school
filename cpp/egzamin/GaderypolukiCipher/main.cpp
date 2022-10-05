#include <iostream>

using namespace std;

/*
    - nazwa funkcji: gaderypolukiCipher
    - parametry wejsciowe: zmienna typu string
    - wartosc zwracana: zaszyfrowany ciag znakow szyfrem
        podstawieniowym
    - opis funkcji: uzytkownik podaje ciag znakow, ktory
        zostaje zaszyfrowany szyfrem podstawieniowym, pierwsza
        litera w parze jest zastepowana na druga, druga na pierwsza,
        nastepnie ciag zostaje zwrocony
        przyklad: konsola => ipnspug
    - autor: ME
*/

string gaderypolukiCipher(string str)
{
    string cipher = "gaderypoluki";
    for(int i=0; i<str.length(); i++)
    {
        for(int j=0; j<cipher.length(); j++)
        {
            if(str[i] == cipher[j] && j%2==0)
            {
                str[i] = cipher[j+1];
                break;
            }
            else if(str[i] == cipher[j] && j%2!=0)
            {
                str[i] = cipher[j-1];
                break;
            }
            else
                str[i] = str[i];
        }
    }
    return str;
}

int main()
{
    string text, result;
    cout << "Enter a text: "; cin >> text;
    result = gaderypolukiCipher(text);
    cout << result;
    return 0;
}
