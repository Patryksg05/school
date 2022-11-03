import java.util.Random;
import java.util.Scanner;

public class PaperRockScissors {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        String playerMovement;
        int computerScore = 0;
        int playerScore = 0;

        System.out.println("\nP A P E R - R O C K - S C I S S O R S");

        while(true)
        {
            String[] movement = {"paper", "rock", "scissors"};
            String computerMovement = movement[new Random().nextInt(movement.length)];

            while(true) {
                System.out.print("Your move: ");
                playerMovement = scanner.nextLine();
                if (playerMovement.equals("paper") || playerMovement.equals("rock")
                        || playerMovement.equals("scissors"))
                    break;
                System.out.println("Movement is not available");
            }

            System.out.println("Computer move: " + computerMovement);

            if(playerMovement.equals(computerMovement)){
                System.out.println("Ops, draw...");
            }
            else if(playerMovement.equals("paper")) {
                if (computerMovement.equals("rock")) {
                    System.out.println("You win!");
                    playerScore++;
                } else if (computerMovement.equals("scissors")) {
                    System.out.println("Computer win!");
                    computerScore++;
                }
            }
            else if(playerMovement.equals("rock")) {
                if (computerMovement.equals("paper")) {
                    System.out.println("Computer win!");
                    computerScore++;
                } else if (computerMovement.equals("scissors")) {
                    System.out.println("You win!");
                    playerScore++;
                }
            }
            else if(playerMovement.equals("scissors")) {
                if (computerMovement.equals("paper")) {
                    System.out.println("You win!");
                    playerScore++;
                } else if (computerMovement.equals("rock")) {
                    System.out.println("Computer win!");
                    computerScore++;
                }
            }

            System.out.println("\nR E S A U L T");
            System.out.println("\t PLAYER: " + playerScore + " vs COMPUTER: " + computerScore + "\n");

            System.out.print("Play one more time? (y/n) = ");
            String oneMore = scanner.nextLine();
            if(!oneMore.equals("y"))
                break;
        }
    }
}
