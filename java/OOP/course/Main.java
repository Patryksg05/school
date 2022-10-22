public class Main {

    public static void main(String[] args) {
        System.out.println("OOP QUIZ 20.10.22\n");
        /**
         * utworz klase kurs: wlasnosci == prywatne, nazwa kursu, prowadzcacy, opis kursu, uczestnicy, cena kursu
         * klasa osoba:  imie, nazwisko
         *      prowadzacy      uczestnik
         *      - umiejetnosci     - fundusz
         *
         * metody: DodajUczestnikaDoKursu (fundusz > ceny kursu, odejmuje fundusz od uczestnika cena - fundusz,
         * nie moze byc wiecej niz 12 osob)
         *
         * wypisujac o kursie wypisujemy prowadzacego
         *
         * Testy = 2 obiekty kursy, min 1 prowadzacy, min 2|3 uczestnikow
         */

        Kurs kurs1 = new Kurs("Kartkowka", "pozdrawiam z kartkowki", 200);

        Prowadzacy prowadzacy1 = new Prowadzacy("Janek", "Kiepski", "matematyka");

        Uczestnik uczestnik1 = new Uczestnik("Edward", "Pasikonik", 250);
        Uczestnik uczestnik2 = new Uczestnik("Edward", "Pasikonik", 250);
        Uczestnik uczestnik3 = new Uczestnik("Edward", "Pasikonik", 250);
        Uczestnik uczestnik4 = new Uczestnik("Musze", "Sprawdzic", 500);

        kurs1.dodajProwadzacegoDoKursu(prowadzacy1);

        kurs1.dodajUczesnikaDoKursu(kurs1, uczestnik1);
        kurs1.dodajUczesnikaDoKursu(kurs1, uczestnik1);
        kurs1.dodajUczesnikaDoKursu(kurs1, uczestnik2);
        kurs1.dodajUczesnikaDoKursu(kurs1, uczestnik4);

        System.out.println(kurs1 + "\n");

        Kurs kurs2 = new Kurs("Kartkowka2", "pzdr", 250);

        Prowadzacy prowadzacy2 = new Prowadzacy("Henryk", "Pedziwiatr", "polski");

        kurs2.dodajProwadzacegoDoKursu(prowadzacy2);

        kurs2.dodajUczesnikaDoKursu(kurs2, uczestnik3);
        kurs2.dodajUczesnikaDoKursu(kurs2, uczestnik4);

        System.out.println(kurs2);
    }

}
