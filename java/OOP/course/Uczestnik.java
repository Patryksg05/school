public class Uczestnik extends Osoba{
    /**
     * utworz klase kurs: wlasnosci == prywatne, nazwa kursu, prowadzcacy, opis kursu, uczestnicy, cena kursu
     * klasa osoba:  imie, nazwisko
     *      prowadzacy      uczestnik
     *      - umiejetnosci     - fundusz
     *
     * metody: DodajUczestnikaDoKursu (fundusz > ceny kursu,
     * odejmuje fundusz od uczestnika cena - fundusz,
     * nie moze byc wiecej niz 12 osob)
     *
     * wypisujac o kursie wypisujemy prowadzacego
     *
     * Testy = 2 obiekty kursy, min 1 prowadzacy, min 2|3 uczestnikow
     */

    private int fundusz;

    public Uczestnik(String imie, String nazwisko, int fundusz) {
        super(imie, nazwisko);
        this.fundusz = fundusz;
    }

    public int getFundusz() {
        return fundusz;
    }

    public void setFundusz(int fundusz) {
        this.fundusz = fundusz;
    }

    @Override
    public String toString() {
        return "Uczestnik{" +
                "imie= " + getImie() +
                " nazwisko= " + getNazwisko() +
                " fundusz=" + fundusz +
                '}';
    }
}
