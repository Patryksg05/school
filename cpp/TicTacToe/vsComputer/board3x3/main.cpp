#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <limits>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void printBoard(char board[3][3]) {
    cout << "\n\t" << board[0][0] << "|" << board[0][1] << "|" << board[0][2];
    cout << "\n\t-+-+-\n";
    cout << "\t" << board[1][0] << "|" << board[1][1] << "|" << board[1][2];
    cout << "\n\t-+-+-\n";
    cout << "\t" << board[2][0] << "|" << board[2][1] << "|" << board[2][2];
    cout << "\n\t-+-+-\n";
}

bool isValidMove(char board[3][3], int position)
{
    switch(position)
    {
        case 1: return (board[0][0] == ' ');
        case 2: return (board[0][1] == ' ');
        case 3: return (board[0][2] == ' ');
        case 4: return (board[1][0] == ' ');
        case 5: return (board[1][1] == ' ');
        case 6: return (board[1][2] == ' ');
        case 7: return (board[2][0] == ' ');
        case 8: return (board[2][1] == ' ');
        case 9: return (board[2][2] == ' ');
        default:
            return false;
    }
}


void placeMove(char board[3][3], int position, char symbol)
{
    switch(position)
    {
        case 1: board[0][0] = symbol; break;
        case 2: board[0][1] = symbol; break;
        case 3: board[0][2] = symbol; break;
        case 4: board[1][0] = symbol; break;
        case 5: board[1][1] = symbol; break;
        case 6: board[1][2] = symbol; break;
        case 7: board[2][0] = symbol; break;
        case 8: board[2][1] = symbol; break;
        case 9: board[2][2] = symbol; break;
        default:
            cout << "Without the range! :(\n";
    }
}

void playerTurn(char board[3][3])
{
    int userInput;
    while(true)
    {
        cout << "\nPLAYER [X] turn => [1-9]: ";
        cin >> userInput;

        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\n\tGiven number should be only a int !!!\n";
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\nPLAYER [X] turn => [1-9]: ";
                cin >> userInput;
            }

            if(!cin.fail())
                break;
        }

        if(isValidMove(board, userInput)) {
            break;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\n\t" << userInput << " is not a valid move!\n";
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    placeMove(board, userInput, 'X');
}

void computerTurn(char board[3][3])
{
    int computerMove;
    while(true)
    {
        computerMove = rand()%9+1;
        if(isValidMove(board, computerMove)) {
            break;
        }
    }
    placeMove(board, computerMove, 'O');

    SetConsoleTextAttribute(hConsole, 14);
    cout << "\nCOMPUTER [O] turn => " << computerMove << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

bool hasContenstantWon(char board[3][3], char symbol)
{
    if(
        (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||

        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||

        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    )
    {
        return true;
    }
    return false;

}

bool isGameFinished(char board[3][3])
{
    if(hasContenstantWon(board, 'X'))
    {
        printBoard(board);
        SetConsoleTextAttribute(hConsole, 2);
        cout << "\n***** T H E  G A M E  IS OVER !!! *****\n\tPLAYER [X] wins\n";
        SetConsoleTextAttribute(hConsole, 15);
        return true;
    }

    if(hasContenstantWon(board, 'O'))
    {
        printBoard(board);
        SetConsoleTextAttribute(hConsole, 2);
        cout << "\n***** T H E  G A M E  IS OVER !!! *****\n COMPUTER [O] wins\n";
        SetConsoleTextAttribute(hConsole, 15);
        return true;
    }

    for(int i=0; i<sizeof(board); i++)
        for(int j=0; j<sizeof(board); j++)
            if(board[i][j] == ' ')
                return false;


    printBoard(board);
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\n***** T H E  G A M E  IS OVER !!! *****\n\t\tDRAW\n";
    SetConsoleTextAttribute(hConsole, 15);
    return true;
}

int main()
{
    SetConsoleTextAttribute(hConsole, 9);
    cout << "***** T I C -- T A C -- T O E => 3X3 VERSION => PvsC *****\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\n\t\tPLAYER VS COMPUTER\n";
    cout << "\n\t PLAYER - [X]\tCOMPUTER - [O]\n";
    string oneMore, result;
    int player, comp = 0;

    while(true)
    {

        char board[3][3] = { {' ', ' ', ' '},
                             {' ', ' ', ' '},
                             {' ', ' ', ' '}
                           };
        printBoard(board);

        while(true)
        {
            playerTurn(board);
            if(isGameFinished(board)) {
                if(hasContenstantWon(board, 'X'))
                    player++;
                break;
            }
            printBoard(board);
            computerTurn(board);
            if(isGameFinished(board)) {
                if(hasContenstantWon(board, 'O'))
                    comp++;
                break;
            }
            printBoard(board);
        }

        cout << "\nTOTAL SCORE:\tPLAYER [X] = " << player << "\tCOMPUTER [O] = " << comp;
        cout << "\n\tPlay one more time? (y/n) => ";
        cin >> oneMore;
        if(oneMore != "y") {
            SetConsoleTextAttribute(hConsole, 9);
            if(player > comp)
                result = "\n\tPlayer [X] was better!";
            else if (player < comp)
                result = "\n\tComputer [O] was better!";
            else if(player == comp)
                result = "\n\tPlayer [X] && Computer [O] have a draw :O";
            else
                result = "\n\tNobody won :(";

            cout << endl << result << endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
    }

    return 0;
}
