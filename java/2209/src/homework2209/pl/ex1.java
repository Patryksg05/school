package homework2209.pl;

import java.util.Arrays;

public class ex1 {
    public static void main(String[] args) {
        /*
            Zadeklaruj tablicę 10 liczb rzeczywistych i
            wypełnij ją pierwiastkami jej indeksów.
         */

        // wersja 1
        System.out.println("Wersja 1: (double)");
        int[] tab = new int[10];
        double[] doubleTab = Arrays.stream(tab).asDoubleStream().toArray();
        for(int i=0; i<10; i++)
            doubleTab[i] = Math.sqrt(i);

        for(double j:doubleTab)
            System.out.print(j+" ");

        // wersja 2
        System.out.println("\nWersja 2: (int)");
        int[] tabb = new int[10];
        for(int i=0; i<10; i++) {
            tabb[i] = (int) (Math.pow(i, 0.5));
            System.out.print(tabb[i] + " ");
        }
    }
}
