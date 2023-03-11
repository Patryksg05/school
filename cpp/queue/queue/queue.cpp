#include <iostream>
#include <queue>

using namespace std;

class Kolejka {
public:
	queue<int> liczby;
	Kolejka() {}
	Kolejka(const Kolejka& kolejka) { liczby = kolejka.liczby; }
	~Kolejka() {}
	int pierwszy() { return liczby.front(); }
	void usun_pierwszy() { liczby.pop(); }
	void dodajNaKoniec(int a) { liczby.push(a); }
	bool pusta() { return liczby.empty(); }
};

int main()
{
	Kolejka* kolejka = new Kolejka();
	bool runner = true;
	cout << "MENU:\n1.PIERWSZY ELEMENT\n2.USUN PIERWSZY ELEMENT\n3.DODAJ ELEMENT NA KONIEC\n"
		<< "4.CZY KOLEJKA JEST PUSTA\n5.USUN KOLEJKE\n6.koniec\nwybor:" << endl;

	while (runner)
	{
		int user_input;
		cin >> user_input;
		switch (user_input)
		{
		case 1:
			if (!kolejka->pusta()) { cout << "pierwszy element: " << kolejka->pierwszy(); }
			else { cout << "kolejka jest pusta!\n"; }
			break;
		case 2: 
			if (!kolejka->pusta()) { cout << "usunieto" << kolejka->pierwszy();  kolejka->usun_pierwszy(); }
			else { cout << "kolejka jest pusta!\n"; }
			break;
		case 3:
			kolejka->dodajNaKoniec(5);
			kolejka->dodajNaKoniec(15);
			kolejka->dodajNaKoniec(12);
			break;
		case 4:
			kolejka->pusta() ? cout << "pusta\n" : cout << "nie pusta\n";
			break;
		case 5:
			kolejka -> ~Kolejka();
		case 6:
			runner = false;
		default:
			break;
		}
	}

}
