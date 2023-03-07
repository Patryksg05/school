#include <iostream>
#include <string>

/*
* POLIMORFIZM => c.p.o. , umozliwiajaca rozne zachowanie tych samych metod wirtulanych w czasie 
*   wykonywania programu, brak slowo kluczowego, inicjuje sie go po przez metody 
*/

using namespace std;

class Bazowa {
public:
	int a = 20;
	virtual void consoleNum() { cout << "a = " << Bazowa::a << endl; }
};

class Pochodna : public Bazowa {
public:
	int b = 12;
	void consoleNum() { cout << "b = " << Pochodna::b << endl; }
};

class Pojazd {
public:
	virtual void zatrzymaj() { cout << "zatrzymaj pojazd:.... (defualt)" << endl; }
};

class Samochod : public Pojazd {
public:
	void zatrzymaj(){ cout << "zatrzymaj pojazd: samochod" << endl; }
};

class Rower : public Pojazd {
public:
	void zatrzymaj() { cout << "zatrzymaj pojazd: rower" << endl; }
};

class Liczba {
public: 
	double re;
	virtual double modul() { return std::abs(re); }
	bool wieksza(Liczba& ref) { return ref.modul() > Liczba::modul(); }
	double getRe(){ return std::abs(re); }
	double getRef(Liczba& ref){ return ref.modul(); }
};

class Zespolone : public Liczba {
public:
	int im;
	double modul() { return std::sqrt(Liczba::re*Liczba::re + this -> im * this->im); }
	double getIm() { return std::sqrt(Liczba::re * Liczba::re + this->im * this->im); }
};

class Funkcja {
public:
	double x;
	//virtual float value(float x) { return x; }
	virtual double value() = 0;
};

class Funkcja_liniowa : public Funkcja
{
public:
	double a, b;
	double value() {return a * Funkcja::x + b;}
};

double bisekcja(Funkcja_liniowa* f, double p, float k, float d)
{
	double fp = f->x = p;
	double fk = f->x = k;

	if (fp * fk > 0) { cout << "brak mz w danym przedziale!"; 
		return -1; }

	double srodek;
	while ((k - p) > d)
	{
		srodek = (p + k) / 2;
		double fs = f->x = srodek;

		if (fs == 0)
			return fs;
		else if (fp * fs < 0)
		{
			k = srodek;
			fk = fs;
		}
		else
		{
			p = srodek;
			fp = fs;
		}
	}
	return (p + k) / 2;
}	

double function(double x)
{
	return 2*x + 4;
}

void metoda_bisekcji(double a, double b)
{
	if (function(a) * function(b) >= 0)
	{
		cout << "\npiewiastek nie nalezy do przedzialu" << endl;
		return;
	}

	double dokladnosc = 0.001, c = a;

	while ((b - a) >= dokladnosc)
	{
		c = (a + b) / 2;
		if (function(c) == 0)
			break;
		else if (function(c) * function(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "\npierwiastek: " << c;
}

class Czworokat {
protected:
	int a,b,c,d;
public:
	Czworokat(int a=0, int b=0, int c=0, int d=0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	virtual void wypisz(){ cout << this->a << "x" << this->b << "x" << this->c << "x" << this->d << endl ;}
	virtual int pole() { return a * b * c * d; }
};

class Prostokat : public Czworokat {
public:
	Prostokat(int a, int b)
	{
		Czworokat::a = a;
		Czworokat::b = b;
		Czworokat::c = a;
		Czworokat::d = b;
	}

	void wymiary(int w1, int w2)
	{
		Czworokat::a = w1;
		Czworokat::c = w1;
		Czworokat::b = w2;
		Czworokat::d = w2;
	}
	int pole() { return Czworokat::a * Czworokat::b; }
	void wypisz() { cout <<this->a << "x" << this->b << endl; }
};

class Kwadrat : public Czworokat {
public:
	Kwadrat(int a)
	{
		Czworokat::a = a;
		Czworokat::b = a;
		Czworokat::c = a;
		Czworokat::d = a;
	}

	void wymiary(int w1)
	{
		Czworokat::a = w1;
		Czworokat::c = w1;
		Czworokat::b = w1;
		Czworokat::d = w1;
	}
	int pole() { return Czworokat::a * Czworokat::a; }
	void wypisz() { cout << this->a << "x" << this->a << endl; }
};

void wypisz_pola(Czworokat **tab)
{
	for (int i = 0; i < sizeof(tab); i++)
	{
		cout << "pole: " << i + 1 << " czworokata = " << tab[i]->pole() << endl;
	}
}

/*
	uloz algorytm i zapisz go w wybranej notacji, ktory dla 
	dodatniej liczby calkowitej n oblicza max liczbe kolejnych 
	wystepujacych jedynek w zapisie binarnym 
*/

void jedynki_binarnie(int n)
{
	int a = n;
	
	string binary_num;
	int counter = 0, max=0;

	// convert
	while (n)
	{
		binary_num = (n % 2 ? "1" : "0") + binary_num;
		n /= 2;
	}

	for (int i = 0; i < binary_num.size(); i++)
	{
		if (binary_num[i] % 2 == 1)
			counter++;
		if (binary_num[i] % 2 == 0)
			counter = 0;

		if (counter > max)
			max = counter;

	}
	cout << a << " = " << binary_num << " wystapienia 1: " << max << endl;
}

/*
	w systemie trojkowm... 
*/

void trojkowy(double x, int n)
{
	//string result = "0.";
	cout << "0.";
	double y = x;

	for (int i = 1; i <= n; i++)
	{
		if (y >= 2.0 / 3.0)
			cout << "2";
		else if (y >= 1.0 / 3.0 && y < 2.0 / 3.0)
			cout << "1";
		else if (y < 1.0 / 3.0)
			cout << "0";

		y = y * 3.0;

		if (y >= 2.0)
			y -= 2.0;
		else if (y >= 1.0)
			y -= 1.0;
	}
	cout << endl;
}

int main()
{	
	Bazowa* bazowa = new Pochodna();
	Pochodna* pochodna = new Pochodna();

	bazowa->consoleNum();
	pochodna->consoleNum();

	//bazowa = new Bazowa();
	//bazowa->consoleNum();

	Pojazd* pojazd3 = new Pojazd();
	Pojazd* pojazd1 = new Samochod();
	Pojazd* pojazd2 = new Rower();

	pojazd1->zatrzymaj();
	pojazd2->zatrzymaj();
	pojazd3->zatrzymaj();

	Liczba liczba1, liczba2;
	Zespolone zespolone1, zespolone2;
	liczba1.re = -4.65;
	liczba2.re = -5.76;

	zespolone1.re = 1;
	zespolone1.im = -2;
	zespolone2.re = -3;
	zespolone2.im = 4;

	cout << endl << liczba1.getRe() << " < " << liczba1.getRef(liczba2) << " = "
		<< std::boolalpha << liczba1.wieksza(liczba2);
	cout << endl << std::boolalpha << zespolone1.wieksza(zespolone2);

	Funkcja_liniowa f1;
	f1.a = 2.0; // 2x-3
	f1.b = -3.0;
	f1.x = 1; 
	cout << endl << "f(" << f1.x << ") = " << f1.value() << endl;
	metoda_bisekcji(-3, 0);

	cout << endl;
	int a=2, b=2, c=4, d=5;
	Czworokat *czw1 = new Czworokat(a,b,c,d);
	czw1->wypisz();
	cout << "pole cz1 jest rowne: " << czw1->pole();

	cout << endl;
	Czworokat** czworokaty = new Czworokat * [4];
	czworokaty[0] = new Kwadrat(4);
	czworokaty[1] = new Kwadrat(3);
	czworokaty[2] = new Prostokat(2,10);
	czworokaty[3] = new Prostokat(3,5);

	//for (int i = 0; i < 4; i++)
		//czworokaty[i]->wypisz();

	//wypisz_pola(czworokaty);

	// ttps://www.rapidtables.com/convert/number/decimal-to-binary.html
	
	cout << "\nJEDYNKI BINARNIE" << endl;
	jedynki_binarnie(15);
	jedynki_binarnie(20);
	jedynki_binarnie(11);
	jedynki_binarnie(111);
	jedynki_binarnie(211);
	jedynki_binarnie(1024);

	cout << "\nSYSTEM TROJKOWY" << endl;
	trojkowy(0.8, 5);
	trojkowy(0.5, 5);
	trojkowy(0.7, 5);

	return 0;
}   
