import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class KalkulatorTest {

    @org.junit.jupiter.api.Test
     void dodajTestJezeliDodatnie() {
        Kalkulator kalkulator = new Kalkulator();
        int otrzymana = kalkulator.dodaj(2,3);
        int oczekiwana = 8;
        // zwracamy asercje
        Assertions.assertEquals(oczekiwana, otrzymana);
    }

    @Test
    void podzielTestJezeliWynikCalkowity() {
        Kalkulator kalkulator = new Kalkulator();
        double otrzymana = kalkulator.podziel(6,2);
        double oczekiwana = 3;
        Assertions.assertEquals(oczekiwana, otrzymana);
    }
    @Test
    void podzielTestJezeliWynikUlamkiem() {
        Kalkulator kalkulator = new Kalkulator();
        double otrzymana = kalkulator.podziel(2, 4);
        double oczekiwana = 0.5;
        Assertions.assertEquals(oczekiwana, otrzymana);
    }
    @Test
    void podzielTestJezeliDzieleniePrzezZero() {
        Kalkulator kalkulator = new Kalkulator();
        double otrzymana = kalkulator.podziel(2,0);
        double oczekiwana = 0;
        Assertions.assertEquals(oczekiwana, otrzymana);
    }
}