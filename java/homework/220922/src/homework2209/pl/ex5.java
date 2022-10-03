package homework2209.pl;

public class ex5 {

    public static void sieveEratosthenes(int n, int x, int y)
    {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int i = x; i <= y; i++) {
            if (prime[i] == true)
                System.out.print(i + " ");
        }
    }
    public static void main(String[] args) {
        /*
            Wygeneruj tablicę liczb pierwszych mniejszych od 1000.
            Wykorzystaj do tego sito Eratostenesa.
            Wypisz wszystkie liczby pierwsze z zakresu od x do y,
         */
        int num = 1000;
        int x = 10;
        int y = 100;
        sieveEratosthenes(num, x,y);
    }
}
