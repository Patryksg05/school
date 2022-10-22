public final class Prowadzacy extends Osoba{
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

    private String umiejetnosci;

    public Prowadzacy(String imie, String nazwisko, String umiejetnosci) {
        super(imie, nazwisko);
        this.umiejetnosci = umiejetnosci;
    }

    public String getUmiejetnosci() {
        return umiejetnosci;
    }

    public void setUmiejetnosci(String umiejetnosci) {
        this.umiejetnosci = umiejetnosci;
    }

    @Override
    public String toString() {
        return "Prowadzacy{" +
                "imie= " + getImie() +
                "nazwisko = " + getNazwisko() +
                "umiejetnosci='" + umiejetnosci + '\'' +
                '}';
    }
}
