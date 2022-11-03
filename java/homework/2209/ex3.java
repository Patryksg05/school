package homework2209.pl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ex3 {

    public static int countDistnict(int[] tab, int n) {
        Arrays.sort(tab);
        int count = 0;
        for (int i = 0; i < n; i++){
            while(i < n - 1 && tab[i] == tab[i + 1]) {
                i++;
            }
            count++;
//            powtarzajace sie
//            if (i < n - 1 && tab[i] == tab[i + 1]) {
//                count++;
//            }
        }
        return count;
    }

    public static void main(String[] args) {
        /*
            Zadeklaruj tablicę z liczbami całkowitymi i wstaw do
            niej 100 liczb losowych z zakresu od 1 do 100.
            Zadeklaruj dwie kolekcje i wypełnij je wartościami z tablicy.
            Do jednej wstaw liczby parzyste, a do drugiej nieparzyste.
            Podaj, ile różnych liczb wylosowano.
         */

        List<Integer> parzyste = new ArrayList<>();
        List<Integer> nieparzyste = new ArrayList<>();
        int[] tab = new int[100];
        int count = 0;
        for(int i=0; i < tab.length; i++) {
            tab[i] = (int) (Math.random() * 100 + 1);
            if(tab[i]%2==0)
                parzyste.add(tab[i]);
            else
                nieparzyste.add(tab[i]);
        }

        System.out.println("Wylosowano: " + countDistnict(tab, 100) + " roznych liczb");
    }
}
