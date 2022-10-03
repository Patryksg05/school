package homework0915.pl;

import java.util.Scanner;

public class ex2 {
    public static void main(String[] args) {
        /*
            Wczytaj słowo z klawiatury i sprawdź,
            czy jest palindromem, czyli czytane od p
            oczątku do końca i od końca do początku ma takie samo brzmienie.
         */

        Scanner scanner = new Scanner(System.in);
        System.out.print("String = ");
        String string = scanner.nextLine();
        int length = string.length();

        boolean isChar = true;
        int last_element = length-1;
        for(int i=0; i<length; i++) {
            if (string.charAt(i) != string.charAt(last_element)) {
                isChar = false;
                break;
            }
            last_element--;
        }

        String answer = isChar==true? "Is palindrom!":"It isn't palindrom!";
        System.out.println(answer);
    }
}
