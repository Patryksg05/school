package homework0915.pl;

import java.util.Scanner;

public class ex6 {
    public static int silnia(int n)
    {
        int i, s;
        i = s = 1;
        while(i<=n)
        {
            s *= i;
            i++;
        }
        return s;
    }

    public static void main(String[] args) {
        /*
            Napisz program obliczający sumę silni cyfr z liczby.
         */
        Scanner scanner = new Scanner(System.in);
        System.out.print("Z ilu cyfr sklada sie liczba: ");
        int size = scanner.nextInt();
        int[] cyfry = new int[size];
        int k = 0;
        for(int j=0; j<size; j++) {
            System.out.print("Podaj "+ ++k + " cyfre = ");
            cyfry[j] = scanner.nextInt();
        }
//        System.out.println(cyfry.length);
        int[] tabSilnia = new int[size];
        int sumaSilni = 0;
        for(int i=0; i<cyfry.length; i++)
        {
            tabSilnia[i] = silnia(cyfry[i]);
            sumaSilni += tabSilnia[i];
        }
        System.out.println("Suma silni cyfr liczby jest rowna: " + sumaSilni);
    }
}