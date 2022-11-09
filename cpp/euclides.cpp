#include <iostream>

using namespace std;

/**
        Dany jest ciag a(n) okreœlony jako: 1 dla n=0, 2*a(n-1) dla n>0.
        1) przygotuj arkusz kalkulacyjny obliczaj¹cy kolejne wyrazy ci¹gu
        2) co to za ci¹g? jakie wartoœci reprezentuj¹ wyrazy tego ci¹gu?
        3) napisz program lub pseudokod zawieraj¹cy dwie funkcje obliczaj¹ce n-ty wyraz ci¹gu:
            - iteracyjnie
            - rekurencyjnie
**/

int ciagRekurencyjnie(int n) {
    if(n <= 0) {
        return 1;
    }
    return 2*ciagRekurencyjnie(n-1);
}

int ciagInteracyjnie(int n) {
    int result = 1;
    while(n>0) {
        result*=2;
        cout << result << " ";
        n--;
    }
    return result;
}

void euklides(int a, int b)
{
    int x,y;
	if(b!=0)
	{
		euklides(b, a%b); // NWD
		int pom = y;
		y = x  - a/b*y;
		x = pom;
	}
}

long long potega(int a, int b) {
    if(b == 0)
        return 1;
    return a*potega(a, b-1);
}

long long szybkiePotegowanie(int a, int b) {
    if(b == 0)
        return 1;

    if(b%2 == 0) {
        int s = szybkiePotegowanie(a, b/2);
        return s * s;
    }
    else {
        int s = szybkiePotegowanie(a, b-1);
        return a*s;
    }
}

long long silnia(int n) {
//    int silnia = 1;
//    while(n>0) {
//        silnia *= n;
//        n--;
//    }
    if(n<2)
        return 1;
    return n*silnia(n-1);
}

int main()
{
    // CIAG GEOMETRYCZNY
    int ciagR = ciagRekurencyjnie(5);
    cout << "CIAG GEOMETRYCZNY:\nrekurencyjnie => "<< ciagR << endl;
    int ciagI = ciagInteracyjnie(5);
    cout << "=> " << ciagI << endl;

    // ROZ EUKLIDES
    int a,b,x=1,y=0;
    cout << "NWD:\nWprowadz liczby:" << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    euklides(a,b);
    cout << "nwd("<<a<<","<<b<<") = " << a << "*" << x <<
        "+" << b << "*" << y << " = " << a*x+b*y;

    // POTEGA
    int pot = potega(2,5);
    cout << "\nPotega = " << pot;
    cout << "\nPotega wersja2 = " << szybkiePotegowanie(2,5);

    // SILNIA
    int sil = silnia(5);
    cout << "\nSilnia = "<< sil;

    return 0;
}
