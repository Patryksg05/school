abstract public class Osoba {
    /**
     * utworz klase kurs: wlasnosci == prywatne, nazwa kursu, prowadzcacy, opis kursu, uczestnicy, cena kursu
     * klasa osoba:  imie, nazwisko
     *      prowadzacy      uczestnik
     *      - umiejetnosci     - fundusz
     *
     *      z prowadzacego nikt nie dziedzicy
     *
     * metody: DodajUczestnikaDoKursu (fundusz > ceny kursu, odejmuje fundusz od uczestnika cena - fundusz,
     * nie moze byc wiecej niz 12 osob)
     *
     * wypisujac o kursie wypisujemy prowadzacego
     *
     * Testy = 2 obiekty kursy, min 1 prowadzacy, min 2|3 uczestnikow
     */

    private String imie;
    private String nazwisko;

    public Osoba(String imie, String nazwisko) {
        this.imie = imie;
        this.nazwisko = nazwisko;
    }

    public String getImie() {
        return imie;
    }

    public void setImie(String imie) {
        this.imie = imie;
    }

    public String getNazwisko() {
        return nazwisko;
    }

    public void setNazwisko(String nazwisko) {
        this.nazwisko = nazwisko;
    }
}
