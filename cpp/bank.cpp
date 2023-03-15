#include <iostream>

using namespace std;

/*
Zadanie Bankomat Klasa Bankomat powinna zawiera� prywatne pola przechowuj�ce aktualny
stan konta oraz numer PIN u�ytkownika. Klasa ta powinna mie� publiczne metody
umo�liwiaj�ce wp�at� i wyp�at� pieni�dzy z konta oraz zmian� PIN-u.
Do klasy Bankomat dodaj przyjacielsk� .*/

class Bank {
private:
	int stanKonta;
	int userPin;
	int num;

public:

	Bank(int sk = 100, int up = 11111111)
	{
		this->stanKonta = sk;
		this->userPin = up;
	}

	int getStanKonta() { return this->stanKonta; }
	int getUserPin() { return this->userPin; }
	int setUserPin(int p) { this->userPin = p; }

	void wplac()
	{
		cout << "\n\nile wplacic?=";
		cin >> num;
		stanKonta += num;
		cout << "\nSTAN KONTA: " << getStanKonta();
	}

	void wyplac()
	{
		cout << "\nile wyplacic?=";
		cin >> num;
		if (stanKonta > num)
			stanKonta -= num;
		else
			cout << "\nnie masz tyle na koncie!";
		cout << "\nSTAN KONTA: " << getStanKonta();
	}

	friend class Serwis;

};

/*
klas� Serwis, kt�ra pozwoli na zresetowanie stanu konta i PIN-u. Klasa Serwis powinna mie� prywatne pola przechowuj�ce
domy�lny stan konta oraz domy�lny numer PIN, a tak�e publiczne metody umo�liwiaj�ce resetowanie tych warto�ci.
Dodaj r�wnie� przyjacielsk� funkcj� wy�wietlaj�c� aktualny stan konta i numer PIN u�ytkownika*/

class Serwis {
private:
	int stanKonta = 0;
	int userPin = 00000000;

public:
	void reset(Bank* bank)
	{
		bank->stanKonta = stanKonta;
		bank->userPin= userPin;
		cout << "\nRESET KONTA!!!";
		cout << "STAN KONTA: " << bank->getStanKonta();
		cout << "\nNUMER PIN: " << bank->getUserPin();
	}
};

int main()
{
	//Bank* bank1 = new Bank();
	//bank1->wplac();
	//bank1->wyplac();
	//cout << "Stan konta: " << bank1->getStanKonta();

	Bank* bank1 = new Bank();
	Serwis serwis;
	cout << "STAN KONTA: " << bank1->getStanKonta();
	cout << "\nNUMER PIN: " << bank1->getUserPin();
	bank1->wplac();
	bank1->wyplac();
	serwis.reset(bank1);
}
