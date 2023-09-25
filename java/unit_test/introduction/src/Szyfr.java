public class Szyfr {

    public String szyfruj(String n) {
        String zaszyfrowaneSlowo = "";
        for(int i=0; i<n.length()-1; i+=2)
            zaszyfrowaneSlowo = zaszyfrowaneSlowo + n.charAt(i+1) + n.charAt(i);

        if(n.length()%2!=0) {
            zaszyfrowaneSlowo = zaszyfrowaneSlowo + n.charAt(n.length()-1);
        }

        return zaszyfrowaneSlowo;
    }
}
