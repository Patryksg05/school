#include <iostream>
#include <string>

/*
* POLIMORFIZM => c.p.o. , umozliwiajaca rozne zachowanie tych samych metod wirtulanych w czasie 
*   wykonywania programu, brak slowo kluczowego, inicjuje sie go po przez metody wirtualne
* 
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
};

class Zespolone : public Liczba {
public:
	int im;
	double modul() { return std::sqrt(Liczba::re*Liczba::re + this -> im * this->im); }
};

class Funkcja {
public:
	float x;
	virtual float value(float x) { return x; }
};

class Funkcja_liniowa : public Funkcja
{
public:
	float a, b;
	float value() {return a * Funkcja::x + b;}
};

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

	void wypisz(){ cout << this->a << "x" << this->b << "x" << this->c << "x" << this->d;}
	virtual int pole() { return a * b * c * d; }
};

class Prostokat : Czworokat {
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
};

class Kwadrat : Czworokat {
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
};

double function(double x)
{
	return 2 * x + 4;
}

void metoda_bisekcji(double a, double b)
{
	if (function(a) * function(b) >= 0)
	{
		cout << "piewiastek nie nalezy do przedzialu" << endl;
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
	liczba2.re = -6.76;
	zespolone1.re = 1;
	zespolone1.im = -2;
	zespolone1.re = -3;
	zespolone2.im = 4;
	cout << std::boolalpha << liczba1.wieksza(liczba2);
	cout << endl << std::boolalpha << zespolone1.wieksza(zespolone2);

	Funkcja_liniowa f1;
	f1.a = 2; // 2x-3
	f1.b = -3;
	f1.x = 2; 
	cout << endl << "f(" << f1.x << ") = " << f1.value() << endl;

	int a=2, b=2, c=4, d=5;
	Czworokat *czw1 = new Czworokat(a,b,c,d);
	czw1->wypisz();
	cout <<  endl << czw1->pole();

	metoda_bisekcji(-200, 300);

	//double a = -200, b = 300;
	//metoda_bisekcji(a, b);

	return 0;
}   
