package homework2209.pl;

import java.util.Arrays;

public class ex4 {

    public static double findMediana(int[] tab, int n)
    {
        Arrays.sort(tab);
        if(n%2!=0) return (double)(tab[n/2]);

        return (double)(tab[(n-1)/2] + tab[n/2])/2.0;
    }

    public static void findDominata(int[] tab, int n)
    {
        int maxCount = 0;
        int index = -1;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++) {
                if (tab[i] == tab[j])
                    count++;
            }

            if(count>maxCount) {
                maxCount = count;
                index = i;
            }
        }
        if(index==-1) System.out.println("Brak!");
        System.out.println("Dominanta = " + tab[index]);
    }

    public static double average(int[] tab, int n)
    {
        int suma = 0;
        for(int i=0; i<n; i++)
            suma += tab[i];

        return suma/tab.length;
    }

    public static void main(String[] args) {
        /*
            Wykorzystaj tablicę z zadania 3. z wylosowanymi wartościami.
             - Posortuj tablicę.
             - Znajdź medianę (wartość środkową tablicy),
             - dominantę (wartość najczęściej występującą w tablicy) i
             - wartość średnią wartości zapisanych w tablicy
         */

        int[] tab = new int[50];
        for(int i=0; i<tab.length; i++)
            tab[i] = (int)(Math.random()*100+1);

        System.out.println("Sorted array: ");
        Arrays.sort(tab);
        for(int x: tab)
            System.out.print(x + " ");
        System.out.println("\nMediana = " + findMediana(tab, tab.length));
        findDominata(tab, tab.length);
        System.out.println("Average = " + average(tab, tab.length));
    }
}
