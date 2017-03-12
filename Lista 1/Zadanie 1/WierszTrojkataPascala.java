public class WierszTrojkataPascala {

    private int[] wiersz;
    private int n;
    public WierszTrojkataPascala(int n) throws BlednyArgumentKonstruktora {
        if(n < 0)
            throw new BlednyArgumentKonstruktora(n);
        
        this.n = n;
        wiersz = new int[n + 1];

        for(int i = 0; i < wiersz.length; i++) {
            wiersz[i] = 1;
            for(int j = i - 1; j > 0; j--) {
                wiersz[j] += wiersz[j-1];
            } 
        }
    }

    public int wspolczynnik(int m) throws BlednyArgumentMetody {
        if(m < 0 || m > n)
            throw new BlednyArgumentMetody(n, m);
        return wiersz[m];
    }
}

class BlednyArgumentKonstruktora extends Exception {
    public BlednyArgumentKonstruktora(int n) {
        super("Argument: " + n + " nie jest poprawnym argumentem. Argument powinien byc liczba dodatnia.");
        //Zmienic po policzeniu
    }
}

class BlednyArgumentMetody extends Exception {
    public BlednyArgumentMetody(int n, int m) {
        super("Argument: " + m + " nie jest poprawnym argumentem metody. Argument powinien byc w zakresie [0, " + n + "]");
    }
}