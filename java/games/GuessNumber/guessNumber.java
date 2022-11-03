import java.util.Random;
import java.util.Scanner;

public class guessNumber {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        while(true) {

            System.out.print("\nRange of a random number: ");
            Integer range = Integer.valueOf(scanner.nextLine());
            Random random = new Random();
            Integer randNumber = random.nextInt(range)+1;

            while (true) {
                System.out.print("Enter a number: ");
                Integer number = Integer.valueOf(scanner.nextLine());
                if (number > randNumber)
                    System.out.println("Number is to high!");
                else if (number < randNumber)
                    System.out.println("Number is to low!");
                else {
                    System.out.println("Congrats!, this number was: " + randNumber);
                    break;
                }
            }

            System.out.print("Play one more time? (y/n) = ");
            String oneMore = scanner.nextLine();
            if (!oneMore.equals("y"))
                break;
        }
    }
}
