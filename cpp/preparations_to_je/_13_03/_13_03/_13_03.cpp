#include <iostream>

using namespace std;

class Film {
protected:
    string title; // tytul moze miec max 20 znakow
    int ordered;
public:
    Film()
    {
        this->title = "";
        this->ordered = 0;
    }

    void setTitle(string t) { this->title = t; }
    string getTitle() { return this->title; }
    int getOrdered() { return this->ordered; }
    void orderCounter() { this->ordered++; }
};

class Notatka {
private:
    static int counter;
    int id;
protected:
    string title;
    string content;
public:
    Notatka(string t, string c)
    {
        this->counter += 1;
        this->id = this->counter;
        this->title = t;
        this->content = c;
    }

    void getTitleAndContent() { cout << this->title << " " << this->content; }
    void toString()
    {
            cout << "\n" << this->id
            << "\n" << this->title
            << "\n" << this->content;
    }
};

int Notatka::counter = 0;

// SORTOWANIE PRZEZ WYBIERANIE

class Tab {
private:
    int size = 5;
    int* tab;

    int getMaxi()
    {
        int maxi = tab[0];
        for (int i = 0; i < size; i++)
        {
            if (maxi < tab[i])
                maxi = tab[i];
        }
        return maxi;
    }

public:
    Tab() { this->tab = new int[size]; }

    void sortMethod()
    {
        int min_index;
        for (int i=0; i<size-1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (tab[j] > tab[min_index])
                    min_index = j; 
            }

            int temp = tab[min_index];
            tab[min_index] = tab[i];
            tab[i] = temp;
        }
    }

    void setValues()
    {
        cout << "wpisz dane: \n";
        for (int i = 0; i < size; i++)
        {
            int element = 0;
            cout << i + 1 << ". "; cin >> element;
            tab[i] = element;
        }
    }

    void displayArray()
    {
        for (int i = 0; i < size; i++)
            cout << tab[i] << " ";
    }
};

int main()
{
    /* zad 1.1
    Film* film = new Film();
    cout << "Przed dodaniem: " << film->getOrdered();
    film->orderCounter();
    film->setTitle("reksio");
    cout << "\nPo dodaniu: " << film->getOrdered() << ". ";
    cout << film->getTitle(); */

    /* zad1.2
    Notatka* notatka = new Notatka("first note", "aaa");
    Notatka* notatka2 = new Notatka("Second note", "bbb");

    notatka->getTitleAndContent();
    notatka->toString();
    cout << endl << endl;
    notatka2->getTitleAndContent();
    notatka2->toString(); */

    Tab *tab = new Tab();
    tab->setValues();
    tab->sortMethod();
    tab->displayArray();
}
