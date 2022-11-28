import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("TIC TAC TOE :D\n");

        char board[][] = {{'1', '2', '3'} , {'4', '5' , '6'}, {'7' , '8' , '9'}};

        displayBoard(board);

        Scanner scanner = new Scanner(System.in);
        playernTurn(board, scanner);

        displayBoard(board);
    }

    private static void playernTurn(char board[][], Scanner scanner)
    {
        System.out.println("Where would you like to play? (1-9)");
        int userChoice = scanner.nextInt();
    }

    private static void displayBoard(char board[][]) {
        System.out.println(board[0][0] + "|" + board[0][1] + "|" + board[0][2]);
        System.out.println("-----");
        System.out.println(board[1][0] + "|" + board[1][1] + "|" + board[1][2]);
        System.out.println("-----");
        System.out.println(board[2][0] + "|" + board[2][1] + "|" + board[2][2]);
        System.out.println("-----");
    }
}