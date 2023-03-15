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
	void getQueue() {
		for(int i=0; i<liczby.size(); i++)
		{
			cout << liczby.front() << " ";
			liczby.push(liczby.front());
			liczby.pop();
		}	
		}
};

class Wierzcholek {
public:
	Wierzcholek* ojciec;
	Wierzcholek* lewy_syn;
	Wierzcholek* prawy_syn;

public:
	//const int wartosc;
	//Wierzcholek(int wartosc) : wartosc(wartosc), ojciec(nullptr),
		//lewy_syn(nullptr), prawy_syn(nullptr) {};
	int wartosc;
	Wierzcholek(int w)
	{
		this->wartosc = w;
		this->ojciec = NULL;
		this->lewy_syn = NULL;
		this->prawy_syn = NULL;
	}


	bool getOjciec() { return this->ojciec; }
	bool getLewySyn() { return this->lewy_syn; }
	bool getPrawySyn() { return this->prawy_syn; }
};

//class Drzewo {
//protected:
//	Wierzcholek* wierzcholek;
//public:
//	Drzewo(int wartosc)
//	{
//		wierzcholek = new Wierzcholek(wartosc);
//	}
//	//virtual ~Drzewo() { usun_drzewo(wierzcholek); }
//	~Drzewo() { delete wie3rzcholek; }
//private:
//	//void usun_drzewo(Wierzcholek *wsk)
//	//{
//		//if (wsk == nullptr)
//			//return;
//		//usun_drzewo(wsk->lewy_syn);
//		//usun_drzewo(wsk->prawy_syn);
//		//delete wsk;
//	//}
//
//	void wstaw(int wartosc, Wierzcholek* wsk, bool strona)
//	{
//		Wierzcholek* nowy_w = new Wierzcholek(wartosc);
//		nowy_w->ojciec = wsk;
//
//		if (strona && wsk->lewy_syn == nullptr)
//			wsk->lewy_syn = nowy_w;
//		else if(!strona && wsk->prawy_syn == nullptr)
//			wsk->prawy_syn = nowy_w;
//	}
//
//	
//};


class Drzewo {
public:
	Wierzcholek* w;
	Drzewo(int wartosc)
	{
		w = new Wierzcholek(wartosc);
	}
	
	virtual ~Drzewo() { delete w; }

	void wstaw(int wartosc, Wierzcholek* wsk, bool strona) {
		if (strona && wsk->lewy_syn == NULL)
			wsk->lewy_syn = new Wierzcholek(wartosc);
		else if(!strona && wsk->prawy_syn == NULL) {
			wsk->prawy_syn = new Wierzcholek(wartosc);
		}
	}

	//void usun_drzewo(Wierzcholek *wsk)
//	//{
//		//if (wsk == NULL)
//			//return;
//		//usun_drzewo(wsk->lewy_syn);
//		//usun_drzewo(wsk->prawy_syn);
//		//delete wsk;
//	//}

	//virtual Wierzcholek* nastepny(Wierzcholek* wsk) = 0;
};





int main() 
{
	/*
	Wierzcholek* w = new Wierzcholek(5);
	//cout << w->wartosc << " " << boolalpha << w->getOjciec() << 
		//boolalpha << " " << w->getLewySyn() <<
		//boolalpha << " " << w->getPrawySyn() << endl;
	Drzewo* drzewo = new Drzewo(10);
	Wierzcholek* korzen = drzewo->w;
	drzewo->wstaw(1, korzen, true); // lewy syn korzenia
	drzewo->wstaw(2, korzen, false); // prawy syn korzenia
	drzewo->wstaw(3, korzen->lewy_syn, false); // prawy syna lewego korzenia
	drzewo->wstaw(3, korzen->prawy_syn, true); // lewy syn prawego korzenia
	delete drzewo;
	*/

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
				if (kolejka->pusta())
					cout << "\nkolejka jest pusta!";
				else {
					cout << endl;
					kolejka->getQueue();
				}
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
