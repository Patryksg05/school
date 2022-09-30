#include <iostream>

using namespace std;

// content: multiplication table with 3D array

void array3D(){
    int row, column, floor;
    cout << "Wiersz = "; cin >> row;
    cout << "Kolumna = "; cin >> column;
    cout << "Pietro = "; cin >> floor;
    int tab[row][column][floor];
    for(int k=1; k<=floor; k++){
        for(int j=1; j<=row; j++){
            for(int i=1; i<=column;i++){
                tab[i][j][k] = i*j*k;
                cout << i << "*" << j << "*" << k << "="
                << tab[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    array3D();
    return 0;
}
