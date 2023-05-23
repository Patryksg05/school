#include <iostream>
#define SIZE 50

using namespace std;

class Tab {
private:
    int tab[10];
public:
    void generateTab()
    {
        for (int i = 0; i < 10; i++)
            tab[i] = rand() % 30;
    }
    int getMiniValue()
    {
        int mini = tab[0];
        for (int i = 0; i < 10; i++)
            if (tab[i] < mini)
                mini = tab[i];
        return mini;
    }

    int getMaxValue(int index)
    {
        int maxi = index;
        for (int i = index; i < 10; i++)
        {
            if (tab[maxi] < tab[i])
                maxi = i;
        }
        return maxi;
    }

    void displayTab()
    {
        for (int i = 0; i < 10; i++)
            cout << tab[i] << " ";
    }
    void sort()
    {
        int pom = 0;
        for (int i = 0; i < 10; i++)
        {
            int a = getMaxValue(i);
            pom = tab[i];
            tab[i] = tab[a];
            tab[a] = pom;
        }
        displayTab();
    }
};
bool wartownik(int tab[SIZE], int n)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (tab[i] == n && i != SIZE-1)
        {
            return false;
            break;
        }
    }
    return true;
}

int returnIndex(int tab[SIZE], int element)
{
    for(int i=0; i<SIZE; i++)
        if (tab[i] == element)
        {
            return i;
            break;
        }
    return -1;
}

int main()
{
    srand(time(NULL));
    int tab[SIZE];

    for (int i = 0; i < SIZE; i++)
        tab[i] = rand() % 101;
   
    int element;
    cin >> element;
    tab[SIZE - 1] = element;

    for (int i = 0; i < SIZE; i++)
        cout << tab[i] << " ";

    wartownik(tab, element) ? cout << endl << element << " = wartownik" : cout << endl << returnIndex(tab, element);

    cout << "\n\nZADANIE 1.1" << endl;

    Tab tab1;
    tab1.generateTab();
    tab1.displayTab();
    cout << endl << "MIN: " << tab1.getMiniValue() << endl;
    tab1.sort();

    return 0;
}
