package homework0915.pl;

import java.util.Random;
import java.util.Scanner;

public class ex8 {
    public static void main(String[] args) {
        /*
            Wygeneruj hasło losowe.
            Długość hasła powinna wynosić 20 znaków, a ponadto
            powinno zawierać liczby, wielkie i małe litery oraz znaki specjalne.
         */

        String upperCase = "ABCDEFGHIJKLMNOPRSTWUXYZ";
        String lowerCase = "abcdefgihijklmnoprstwuxyz";
        String numbers = "0123456789";
        String specialCharacters = "!@#$%&?";
        String sum = upperCase + lowerCase + numbers + specialCharacters;
        int length = sum.length();
        char[] password = new char[20];
        Random random = new Random();
        for(int i=0; i<20; i++)
            password[i] = sum.charAt(random.nextInt(length));
        System.out.println(password);

    }
}
