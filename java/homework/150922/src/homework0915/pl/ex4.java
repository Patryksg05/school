package homework0915.pl;

public class ex4 {
    public static void main(String[] args) {
        /*
            Wczytaj słowo z klawiatury i zaszyfruj je szyfrem Cezara z kluczem 3.
            Szyfr Cezara polega na przesunięciu każdej litery alfabetu w prawo o klucz.
         */

        String text = "XHJFHDFOJhdhjahdhJDFH";
        int key = 3;
        StringBuffer results = new StringBuffer();

        for(int i=0; i<text.length(); i++)
        {
            if(Character.isUpperCase(text.charAt(i)))
            {
                char character = (char) (((int) text.charAt(i) + key-65)%26+65);
                results.append(character);
            }
            else
            {
                char character = (char)(((int)text.charAt(i) + key-97)%26+97);
                results.append(character);
            }
        }

        System.out.println("Text: " + text);
        System.out.println("Cipher: " + results);

    }
}

        /*
            // lower case
            (char - 97)%26+97
            -97 => Najpierw obliczamy pozycję bieżącej
            litery w alfabecie, a następnie bierzemy jej kod
            ASCII i odejmujemy od niej kod ASCII litery a.
            % => Następnie stosujemy przesunięcie do tej pozycji,
            ostrożnie używając modulo, aby pozostać w zakresie alfabetu.
            https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
            +97 => I na koniec pobieramy nowy znak, dodając
            nową pozycję do kodu ASCII litery a.
         */
