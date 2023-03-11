#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

class Kolejka {
public:
	queue<int> liczby;
	string nazwa_kolejki;
	Kolejka() {}
	Kolejka(const Kolejka& kolejka) { liczby = kolejka.liczby; }
	~Kolejka() {}
	int pierwszy() { return liczby.front(); }
	void usun_pierwszy() { liczby.pop(); }
	void dodajNaKoniec(int a) { liczby.push(a); }
	bool pusta() { return liczby.empty(); }
	void setNazwa(string n) { this->nazwa_kolejki = n; }
	string getNazwa() { return this->nazwa_kolejki; }
	int size() { return liczby.size(); }
};

int main()
{
	//cout << "MENU\n1.Utworz kolejke\n2.Pierwszy element\n3.Dodaj element na koniec"
		//<< "\n4.Usun pierwszy element\n5.Czy kolejka jest pusta\n6. Wypisz elementy\n7.wyjscie";
	cout << "MENU\n1.Utworz kolejke\n";

	bool runner = true;
	Kolejka* kolejka;

	while (true)
	{
		int n;
		cout << endl << "wybor:"; cin >> n;
		if (n != 1) cout << "\t1. UTWORZ KOLEJKE!";

		if (n == 1)
		{
			string nazwa_kolejki;
			kolejka = new Kolejka();
			cout << endl << "Nazwa kolejki: "; cin >> nazwa_kolejki;
			kolejka->setNazwa(nazwa_kolejki);
			break;
		}
	}

	system("CLS");
	cout << "UTWORZONO KOLEJKE: " << kolejka->getNazwa();
	cout << "\n1.Pierwszy element\n2.Dodaj element na koniec"
		<< "\n3.Usun pierwszy element\n4.Czy kolejka jest pusta\n5.Wypisz elementy\n6.usun kolejke\n7.wyjscie";

	while (runner)
	{
		int user_input, element;
		cout << endl << "wybor: "; cin >> user_input;
		
		switch (user_input)
		{
			case 1: kolejka->pusta() ? cout << "\nkolejka jest pusta!" 
				: cout << "\npierwszy element: " << kolejka->pierwszy(); 
				break;
			case 2: 
				int a;
				cout << "\nIle elementow dodac?"; cin >> a;
				for (int i = 0; i < a; i++)
				{
					cout << i + 1 << ". element = "; cin >> element;
					kolejka->dodajNaKoniec(element);
				}
				break;
			case 3:
				kolejka->pusta() ? cout << "\nkolejka jest pusta!" : cout << "\nusunieto element: " << kolejka->pierwszy();
				kolejka->usun_pierwszy();
				break;
			case 4:
				cout << "\nkolejka pusta?=" << boolalpha << kolejka->pusta();
				break;
			case 5:

				break;
			case 6:
				cout << "\ndestruktor :cc";
				kolejka->~Kolejka();
				return 0;
				break;
			case 7: return 0; break;
			default:
				break;
		}
	}
}
