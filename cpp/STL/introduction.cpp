#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{

//     VECTOR
//        vector<int> numbers = {10,54,44,534};
//        numbers.push_back(12); // dodawanie elementow na koniec wektora
//        numbers.push_back(15);
//
//        cout << numbers[1] << endl;
//        cout << numbers.at(1) << endl;
//
//        // sort(numbers.begin(), numbers.end());
//
//        numbers.at(5) = 10;
//        numbers.pop_back();
//        numbers.erase(numbers.begin()+2);
//        // numbers.clear(); usuniecie calego vectora
//
//        for(int number: numbers) {
//            cout << number << " "; // number.at(i)
//        }
//
//        cout << "\n" << numbers.size() << endl;
//
//     SET: unikatowe wartosci, odrazu posortowane
//        set<string> names = {"John"};
//        names.insert("John");
//        names.insert("Patrick");
//        names.erase("Patrick");
//
//        for(string name: names) {
//            cout << name << " ";
//    }

    // MAP: klucz wartosc :D

    map<string, string> countriesAndCapitals;
    countriesAndCapitals.insert(pair<string, string>("Poland", "Zabrze"));
//    countriesAndCapitals.insert(pair<string, string>("Germany", "Dortmund"));
    countriesAndCapitals.insert(pair<string, string>("Hungary", "Budapest"));
    countriesAndCapitals.insert({"Germany", "Berlin"});

//    cout << countriesAndCapitals.at("Poland"); // po kluczu
//    cout <<  "\n" << countriesAndCapitals["Hungary"]; // at > []
//
//
//
//     for(map<string, string>::iterator )
//     iterator wskazujacy na poczatek mapy
//     -> pobieranie element ze zmiennej wskaznikowej

    countriesAndCapitals.at("Poland") = "Warsaw";
    countriesAndCapitals.erase("Germany");
//    countriesAndCapitals.clear(); => usuwanie wszystkiego

    int k = 0;
    for(auto it=countriesAndCapitals.begin();
        it!= countriesAndCapitals.end(); ++it) { // preinkrementacja
        cout << ++k << ". " << it -> first << " - " << it -> second << endl;
    }

    return 0;
}
