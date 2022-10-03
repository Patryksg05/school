package homework0915.pl;

import java.util.Scanner;

import static java.lang.String.valueOf;

public class ex3 {

    public static boolean isPalin(String liczba)
    {
//        String num = valueOf(liczba);
        int lastElement = liczba.length()-1;

        for(int i=0; i<liczba.length();i++)
        {
            if(liczba.charAt(i)!=liczba.charAt(lastElement))
            {
                return false;
            }
            lastElement--;
        }
        return true;
    }

    public static void findPalindor(int num)
    {
        int lower = num-1;
        // lower mniejszy od palin
        while(isPalin(Integer.toString(lower)) == false)
        {
            lower--;
        }

        int greater = num+1;
        // greater wiekszy od palin
        while (isPalin(Integer.toString(greater)) == false)
        {
            greater++;
        }

        if(Math.abs(num-greater) < Math.abs(num-lower))
            System.out.println("\tNajblizszy palindrom = " + greater);
        else
            System.out.println("\tNajblizszy palindrom = " + lower);

    }

    public static void main(String[] args) {

//        https://www.geeksforgeeks.org/stringbuilder-reverse-in-java-with-examples/
//        https://www.geeksforgeeks.org/closest-palindrome-number-whose-absolute-difference-min/

        /*
            Znajdź dla danej liczby najbliższą jej liczbę palindromiczną
            (czytana od początku jest taka sama jak czytana od końca).
            Dla liczby 1015 najbliższą liczbą palindromiczną jest liczba 1001.
         */

        Scanner scanner = new Scanner(System.in);

        boolean isPalin = true;

        while(isPalin)
        {
            System.out.print("Podaj liczbe = ");
            Integer num = Integer.valueOf(scanner.nextLine());
            if(isPalin(Integer.toString(num)) == true)
                System.out.println("Podana liczba: " +num+ " jest palindromem");
            else
                findPalindor(num);

            System.out.print("Omt? y/n = ");
            String oneMore = scanner.nextLine();
            if(!oneMore.equals("y"))
                isPalin = false;
        }

//        Scanner scanner = new Scanner(System.in);
//        System.out.print("Podaj liczbe: ");
//        int liczba = scanner.nextInt();
//
//        StringBuilder num = new StringBuilder(valueOf(liczba));
//        System.out.println(num);
//        StringBuilder copy = new StringBuilder(num);
//        StringBuilder reverseStr = copy.reverse(); // kopia num revers
//        System.out.println(reverseStr);
//        System.out.println("Przed zmiana: " + num);f
//        System.out.println("Po zmianie: " + reverseStr);
//
//        boolean isPalin = true;
//
//        if(!num.toString().equals(reverseStr.toString()))
//            isPalin = false;
//
//        System.out.println(isPalin);
//
//        String answer = isPalin==true? "Is palindrom!":"It isn't palindrom!";
//        System.out.println(answer);
    }
}
