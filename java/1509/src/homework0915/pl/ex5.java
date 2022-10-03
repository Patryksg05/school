package homework0915.pl;

import java.util.Arrays;
import java.util.Scanner;

public class ex5 {
    public static void main(String[] args) {

        /*
            Wczytaj dwa słowa i sprawdź, czy są one dla siebie anagramami,
            czyli składają się z tych samych liter w takiej samej liczbie.
         */

        Scanner scanner = new Scanner(System.in);

        System.out.print("String1 = ");
        String string1 = scanner.nextLine();
        char str1[] = string1.toCharArray();

        System.out.print("String2 = ");
        String string2 = scanner.nextLine();
        char str2[] = string2.toCharArray();

        boolean isAnagram = true;

        int stringLength1 = str1.length;
        int stringLength2 = str2.length;

        if (stringLength1 != stringLength2)
            isAnagram = false;

        Arrays.sort(str1);
        Arrays.sort(str2);

        for (int i = 0; i < stringLength1; i++)
            if (str1[i] != str2[i])
                isAnagram = false;

//        if(isAnagram==true)
//            System.out.println("Are anagram!");
//        if(!isAnagram==true)
//            System.out.println("Are NOT anagram!");

        String answer = isAnagram == true ? "Are anagram!" : "Are NOT anagram!";
        System.out.println(answer);


//        for(char s1: str1)
//        {
//            for(char s2: str2)
//            {
//                if(s1 == s2)
//                {
//                    System.out.println("jest");
//                }
//                else {
//                    System.out.println("nie jest");
//                }
//            }
//        }

    }
}
