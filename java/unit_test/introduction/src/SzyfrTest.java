import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SzyfrTest {

    @Test
    void szyfrujJezeliTekstPusty() {
        Szyfr szyfr = new Szyfr();
        String oczekiwana = szyfr.szyfruj("");
        String wynik = "";
        Assertions.assertEquals(wynik, oczekiwana);
    }
    @Test
    void szyfrujJezeliTekstDlugosciParzystej() {
        Szyfr szyfr = new Szyfr();
        String oczekiwana = szyfr.szyfruj("abcd");
        String wynik = "badc";
        Assertions.assertEquals(wynik, oczekiwana);
    }

    @Test
    void szyfrujJezeliTekstDlugosciNieParzystej() {
        Szyfr szyfr = new Szyfr();
        String oczekiwana = szyfr.szyfruj("abcde");
        String wynik = "badce";
        Assertions.assertEquals(wynik, oczekiwana);
    }
}