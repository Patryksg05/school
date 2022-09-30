#include <iostream>

using namespace std;

// content: multiplication table with 2D arrau

void array2D(){
    int row, column;
    cout << "Wiersze = "; cin >> row;
    cout << "Kolumny = "; cin >> column;
    int tab[row][column];
    cout << "MULTIPLICATION TABLE\n";
    for(int i=1; i<=row; i++){
        for(int j=1;j<=column; j++){
            tab[i][j] = i*j;
            cout << i << "x" << j << "=" << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    array2D();
    return 0;
}
