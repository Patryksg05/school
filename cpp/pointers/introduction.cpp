#include <iostream>

using namespace std;

void zamiana_zmiennych(int *x, int *y)
{
    cout << "\n\nzmienne przed zamiana\nx = " <<
        *x << "\ny = " << *y;
    int pom = *x;
    *x = *y;
    *y = pom;
    cout << "\nzmienne po zmianie\nx = " <<
        *x << "\ny = " << *y;
}

void zamiana_zmiennych_bez_wsk(int x, int y)
{
    cout << "\n\nzmienne przed zamiana\nj = " <<
        x << "\ni = " << y;
    int pom = x;
    x = y;
    y = pom;
    cout << "\nzmienne po zmianie\nj = " <<
        x << "\ni = " << y;
}

int main()
{
    cout << "POINTERS INTRODUCTION" << endl;

    string food = "Pizza";
    string* ptr = &food;
    cout << "\nadress of variable (food): " << &food;
    cout << "\nzmienna ptr: " << *ptr;
    *ptr = "Hamburger";

    cout << "\nzmienna *ptr po zamianie (food): "
        << food;
    cout << "\nzmienna *ptr: " << *ptr;

    int *a, *b, c;
    b = new int(10);
    c = 5;
    a=&c;
    b = &c;

    cout << "\n\n" << *a << " - " << *b;
    *a = 100;
    //cout << "\nzmienna c po zmianie: " << c;
    cout << "\nzmienne po zamianie: "
        << "\na = " << *a
        << "\nb = " << *b
        << "\nc = " << c;

    cout << "\n\nZAMIANA ZMIENNCYH ZE WSKAZNIKIEM";

    int x = 10, y = 20, j = 5, i = 65;
    zamiana_zmiennych(&x, &y);

    cout << "\n\nzmienna (x) po wyjsciu z funkcji ze wsk: " << x;
    cout << "\nzmienna (y) po wyjsciu z funkcji ze wsk: " << y;

    // wartosci zamieniane zostaja przypisane do zmiennej!
    // x = 20;
    // y = 10;

    cout << "\n\nZAMIANA ZMIENNYCH BEZ WSKAZNIKA: ";
    zamiana_zmiennych_bez_wsk(j, i);

    cout << "\n\nzmienna (j) po wyjsciu z funkcji bez wsk: " << j;
    cout << "\nzmienna (i) po wyjsciu z funkcji bez wsk: " << i
        << "\n";

    int*p = new int[5];
    for(int i=0; i<5; i++) {
        p[i] = i+5;
    }

    cout << "\nfirst element: " << *p << endl;
    cout << "second element: " << *p + 1 << endl;
    cout << "second element: " << 1[p]<< endl;
    cout << "third element: " << 2[p] << endl;

    return 0;
}
