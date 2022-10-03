package homework2209.pl;

import java.util.Scanner;

public class ex2 {

    public static int fibonacci(int n)
    {
        //definicja ciagu fibonacciego nr. ciagu wartosc 0
        if(n<=1)
            return n;
        return fibonacci(n-2)+fibonacci(n-1);
    }

    public static int findClosest(int[] tab,int num)
    {
        int left = 0, right = tab.length, mid = 0, n = tab.length;

        if(num<=tab[0])
            return tab[0];
        if(num>=tab[n-1])
            return tab[n-1];

        // binary search
        while(left<right)
        {
            mid = (left+right)/2; //nr pozycji

            if(tab[mid] == num)
                return tab[mid];

            if(num<tab[mid])
            {
                if(mid>0 && num>tab[mid-1])
                    return getClosest(tab[mid-1], tab[mid], num);
                right = mid;
            }
            else
            {
                if(mid<n-1 && num<tab[mid+1])
                    return getClosest(tab[mid], tab[mid+1], num);
                left = mid+1;
            }
        }
        return tab[mid];
    }

    public static int getClosest(int val1, int val2, int num)
    {
        if(Math.abs(num-val1) >= Math.abs(num-val2))
            return val2;
        else
            return val1;
    }

    public static void main(String[] args) {
        /*
            Zadeklaruj tablicę 40-elementową i wstaw do niej kolejne liczby ciągu Fibonacciego.
            Ciąg Fibonacciego to ciąg, w którym każda kolejna liczba jest równa sumie dwóch poprzednich.
            Wczytaj liczbę i sprawdź, która liczba Fibonacciego jest najbliższa wczytanej liczbie.
            Zadanie wykonaj z wykorzystaniem algorytmu wyszukiwania binarnego.
         */

        Scanner scanner = new Scanner(System.in);

        int[] tab = new int[40];
        for(int i=0; i<tab.length; i++)
            tab[i] = fibonacci(i);

        for(int j: tab)
            System.out.print(j + " ");

        System.out.print("\nYour number: ");
        int num = scanner.nextInt();

        System.out.println(findClosest(tab, num));
    }
}
