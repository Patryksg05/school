package homework0915.pl;

import java.util.Scanner;

public class ex7 {
    public static void main(String[] args) {
        /*
            Sprawdź, czy liczba jest liczbą pierwszą,
            czyli ma dokładnie dwa dzielniki: 1 i samą siebie.
        */
        System.out.println("Is number prime?\n");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Your number = ");
        int number = scanner.nextInt();
        boolean isPrime = true;

        if(number<2)
            isPrime = false;

        for(int i=2; i<number; i++) {
            if (number % i == 0)
                isPrime = false;
        }

        if(!isPrime==true)
            System.out.println("Number: " + number + " is NOT a prime!");
        if(isPrime==true)
            System.out.println("Number: " + number + " is a prime!");

    }
}
