#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void printBoard(char board[5][5]) {
    cout << "\n\t" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << board[0][3] << "|" << board[0][4];
    cout << "\n\t-+-+-+-+-\n";
    cout << "\t" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << board[1][3] << "|" << board[1][4];
    cout << "\n\t-+-+-+-+-\n";
    cout << "\t" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << board[2][3] << "|" << board[2][4];
    cout << "\n\t-+-+-+-+-\n";
    cout << "\t" << board[3][0] << "|" << board[3][1] << "|" << board[3][2] << "|" << board[3][3] << "|" << board[3][4];
    cout << "\n\t-+-+-+-+-\n";
    cout << "\t" << board[4][0] << "|" << board[4][1] << "|" << board[4][2] << "|" << board[4][3] << "|" << board[4][4] << endl;
}

bool isValidMove(char board[5][5], int position)
{
    switch(position)
    {
        case 1: return (board[0][0] == ' ');
        case 2: return (board[0][1] == ' ');
        case 3: return (board[0][2] == ' ');
        case 4: return (board[0][3] == ' ');
        case 5: return (board[0][4] == ' ');
        case 6: return (board[1][0] == ' ');
        case 7: return (board[1][1] == ' ');
        case 8: return (board[1][2] == ' ');
        case 9: return (board[1][3] == ' ');
        case 10: return (board[1][4] == ' ');
        case 11: return (board[2][0] == ' ');
        case 12: return (board[2][1] == ' ');
        case 13: return (board[2][2] == ' ');
        case 14: return (board[2][3] == ' ');
        case 15: return (board[2][4] == ' ');
        case 16: return (board[3][0] == ' ');
        case 17: return (board[3][1] == ' ');
        case 18: return (board[3][2] == ' ');
        case 19: return (board[3][3] == ' ');
        case 20: return (board[3][4] == ' ');
        case 21: return (board[4][0] == ' ');
        case 22: return (board[4][1] == ' ');
        case 23: return (board[4][2] == ' ');
        case 24: return (board[4][3] == ' ');
        case 25: return (board[4][4] == ' ');
        default:
            return true;
    }
    return false;
}


void placeMove(char board[5][5], string position, char symbol)
{
    switch(stoi(position))
    {
        case 1: board[0][0] = symbol; break;
        case 2: board[0][1] = symbol; break;
        case 3: board[0][2] = symbol; break;
        case 4: board[0][3] = symbol; break;
        case 5: board[0][4] = symbol; break;
        case 6: board[1][0] = symbol; break;
        case 7: board[1][1] = symbol; break;
        case 8: board[1][2] = symbol; break;
        case 9: board[1][3] = symbol; break;
        case 10: board[1][4] = symbol; break;
        case 11: board[2][0] = symbol; break;
        case 12: board[2][1] = symbol; break;
        case 13: board[2][2] = symbol; break;
        case 14: board[2][3] = symbol; break;
        case 15: board[2][4] = symbol; break;
        case 16: board[3][0] = symbol; break;
        case 17: board[3][1] = symbol; break;
        case 18: board[3][2] = symbol; break;
        case 19: board[3][3] = symbol; break;
        case 20: board[3][4] = symbol; break;
        case 21: board[4][0] = symbol; break;
        case 22: board[4][1] = symbol; break;
        case 23: board[4][2] = symbol; break;
        case 24: board[4][3] = symbol; break;
        case 25: board[4][4] = symbol; break;
        default:
            cout << "Without the range! :(\n";
    }
}

void playerTurn(char board[5][5])
{
    string userInput;
    while(true)
    {
        cout << "\nPLAYER [X] turn => [1-25]: ";
        cin >> userInput;
        if(isValidMove(board, stoi(userInput)) && (stoi(userInput)<=25)) {
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

void computerTurn(char board[5][5])
{
    int computerMove;
    while(true)
    {
        computerMove = rand()%25+1;
        if(isValidMove(board, computerMove)) {
            break;
        }
    }
    placeMove(board, to_string(computerMove), 'O');
    SetConsoleTextAttribute(hConsole, 9);
    cout << "\nCOMPUTER [O] turn => " << computerMove << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

bool hasContenstantWon(char board[5][5], char symbol)
{
    if(
       (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol && board[0][3] == symbol && board[0][4] == symbol) ||
       (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol && board[1][3] == symbol && board[1][4] == symbol) ||
       (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol && board[2][3] == symbol && board[2][4] == symbol) ||
       (board[3][0] == symbol && board[3][1] == symbol && board[3][2] == symbol && board[3][3] == symbol && board[3][4] == symbol) ||
       (board[4][0] == symbol && board[4][1] == symbol && board[4][2] == symbol && board[4][3] == symbol && board[4][4] == symbol) ||

       (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol && board[3][0] == symbol && board[4][0] == symbol) ||
       (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol && board[3][1] == symbol && board[4][1] == symbol) ||
       (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol && board[3][2] == symbol && board[4][2] == symbol) ||
       (board[0][3] == symbol && board[1][3] == symbol && board[2][3] == symbol && board[3][3] == symbol && board[4][3] == symbol) ||
       (board[0][4] == symbol && board[1][4] == symbol && board[2][4] == symbol && board[3][4] == symbol && board[4][4] == symbol) ||

       (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol && board[3][3] == symbol && board[4][4] == symbol) ||
       (board[4][0] == symbol && board[3][1] == symbol && board[2][2] == symbol && board[1][3] == symbol && board[0][4] == symbol)
    )
    {
        return true;
    }
    return false;

}

bool isGameFinished(char board[5][5])
{
    if(hasContenstantWon(board, 'X'))
    {
        printBoard(board);
        SetConsoleTextAttribute(hConsole, 2);
        cout << "\n***** The game is end *****\n\tPLAYER WINS\n";
        SetConsoleTextAttribute(hConsole, 15);
        return true;
    }

    if(hasContenstantWon(board, 'O'))
    {
        printBoard(board);
        SetConsoleTextAttribute(hConsole, 2);
        cout << "\n***** The game is end *****\n COMPUTER WINS, player lose :((";
        SetConsoleTextAttribute(hConsole, 15);
        return true;
    }

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(board[i][j] == ' ')
                return false;


    printBoard(board);
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\n***** The game is end *****\n\tRESULT => DRAW";
    SetConsoleTextAttribute(hConsole, 15);
    return true;
}

int main()
{
    SetConsoleTextAttribute(hConsole, 9);
    cout << "***** T I C -- T A C -- T O E => 5X5 VERSION *****\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\n\t\tPLAYER VS COMPUTER\n";
    cout << "\n\t PLAYER - [X]\tCOMPUTER - [O]\n";
    char board[5][5] = { {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' ', ' '}
                       };
    printBoard(board);

    while(true)
    {
        playerTurn(board);
        if(isGameFinished(board)) {
            break;
        }
        printBoard(board);
        computerTurn(board);
        if(isGameFinished(board)) {
            break;
        }
        printBoard(board);
    }

    return 0;
}
