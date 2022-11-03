package homework0915.pl;

public class ex1 {
    public static void main(String[] args) {
        /*
            Wypisz na ekranie wszystkie liczby dodatnie
            dwucyfrowe parzyste. Liczby oddziel znakiem spacji.
         */

        System.out.println("\tWersja 1:");
        // wersja 1
        for(int i=10; i<100; i++)
            if(i%2==0)
                System.out.print(i+" ");

        System.out.println("\n\tWersja 2:");

        // wersja 2
        for(int j=10; j<100; j+=2)
            System.out.print(j+" ");
    }
}
