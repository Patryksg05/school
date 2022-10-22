import java.util.ArrayList;

public class Kurs {
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

    private String nazwaKursu;
    private ArrayList<Prowadzacy> prowadzaccy = new ArrayList<Prowadzacy>();
    private String opisKursu;
    private ArrayList<Uczestnik> uczestnicy = new ArrayList<Uczestnik>();
    private int cenaKursu;

    public Kurs(String nazwaKursu, String opisKursu, int cenaKursu) {
        this.nazwaKursu = nazwaKursu;
        this.opisKursu = opisKursu;
        this.cenaKursu = cenaKursu;
    }

    private boolean czyProwadzaczyJuzKursie(Prowadzacy prowadzacy) {
        return prowadzaccy.contains(prowadzacy);
    }

    public void dodajProwadzacegoDoKursu(Prowadzacy prowadzacy) {
        if(!czyProwadzaczyJuzKursie(prowadzacy)) {
            prowadzaccy.add(prowadzacy);
        }
        else
            System.out.println("jest w kursie!");
    }

    private boolean czyUczestnikJestKursie(Uczestnik uczestnik) {
        return uczestnicy.contains(uczestnik);
    }

    public void dodajUczesnikaDoKursu(Kurs kurs, Uczestnik uczestnik) {
//        int max = 13;
        if(uczestnik.getFundusz() >= kurs.getCenaKursu() && !czyUczestnikJestKursie(uczestnik)) {
            if(uczestnicy.size()<12) {
                uczestnicy.add(uczestnik);
                uczestnik.setFundusz(uczestnik.getFundusz()-kurs.getCenaKursu());
            }
            else
                System.out.println("brak miejsc");
        }
        else {
            System.out.println("brak kasy!");
        }
    }

    public String getNazwaKursu() {
        return nazwaKursu;
    }

    public void setNazwaKursu(String nazwaKursu) {
        this.nazwaKursu = nazwaKursu;
    }

    public String getOpisKursu() {
        return opisKursu;
    }

    public void setOpisKursu(String opisKursu) {
        this.opisKursu = opisKursu;
    }

    public int getCenaKursu() {
        return cenaKursu;
    }

    public void setCenaKursu(int cenaKursu) {
        this.cenaKursu = cenaKursu;
    }

    @Override
    public String toString() {
        return "Kurs{" +
                "nazwaKursu='" + nazwaKursu + '\'' +
                ",\nprowadzacy=" + prowadzaccy +
                ", opisKursu='" + opisKursu + '\'' +
                ",\nuczestnicy=" + uczestnicy +
                ",\ncenaKursu=" + cenaKursu +
                '}';
    }
}
