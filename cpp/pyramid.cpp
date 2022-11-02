#include <iostream>
#include <windows.h>

using namespace std;

/**
    content: PYRAMID

    COLORS:             ACTION
        0   BLACK       3 rows => 5 columns
        1   BLUE        4 rows => 7 columns
        2   GREEN       5 rows => 9 columns
        3   CYAN        6 rows => 11 columns
        4   RED         ... ;... <= 2*n - 1; ... ;
        5   MAGENTA
        6   BROWN
        7   LIGHTGRAY
        8   DARKGRAY
        9   LIGHTBLUE
        10  LIGHTGREEN
        11  LIGHTCYAN
        12  LIGHTRED
        13  LIGHTMAGENTA
        14  YELLOW
        15  WHITE

**/

int main()
{
    int n; HANDLE textColor = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "How many rows do you want? = "; cin >> n;
    cout << "\n";

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n*2-1; j++) {
            if(j >= n - (i-1) && j <= n + (i-1)) {
                Sleep(250);
                // SetConsoleTextAttribute(textColor, 12);
                if(j%2==0)
                    SetConsoleTextAttribute(textColor, 5);
                else
                    SetConsoleTextAttribute(textColor, 9);
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
