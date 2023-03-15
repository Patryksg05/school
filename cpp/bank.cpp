#include <iostream>

using namespace std;

/*
Zadanie Bankomat Klasa Bankomat powinna zawieraæ prywatne pola przechowuj¹ce aktualny
stan konta oraz numer PIN u¿ytkownika. Klasa ta powinna mieæ publiczne metody
umo¿liwiaj¹ce wp³atê i wyp³atê pieniêdzy z konta oraz zmianê PIN-u.
Do klasy Bankomat dodaj przyjacielsk¹ .*/

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
klasê Serwis, która pozwoli na zresetowanie stanu konta i PIN-u. Klasa Serwis powinna mieæ prywatne pola przechowuj¹ce
domyœlny stan konta oraz domyœlny numer PIN, a tak¿e publiczne metody umo¿liwiaj¹ce resetowanie tych wartoœci.
Dodaj równie¿ przyjacielsk¹ funkcjê wyœwietlaj¹c¹ aktualny stan konta i numer PIN u¿ytkownika*/

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
