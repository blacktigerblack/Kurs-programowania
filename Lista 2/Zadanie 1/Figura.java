public abstract class Figura {
    public abstract double obwod();
    public abstract double pole();
}

class Okrag extends Figura {
    private double promien;

    public Okrag(double r) throws BlednyBok {
        if(r <= 0)
            throw new BlednyBok();
        
        promien = r;
    }

    public double obwod() {
        return 2 * Math.PI * promien;
    }

    public double pole() {
        return Math.PI * promien * promien;
    }
}

class Pieciokat extends Figura {
    private double bok;

    public Pieciokat(double b) throws BlednyBok {
        if(b <= 0)
            throw new BlednyBok();
        
        bok = b;
    }

    public double obwod() {
        return 5 * bok;
    }

    public double pole() {
        return (bok * bok * Math.sqrt(5 * (5 + 2 * Math.sqrt(5)))) / 4;
    }
}

class Szesciokat extends Figura {
    private double bok;

    public Szesciokat(double b) throws BlednyBok {
        if(b <= 0)
            throw new BlednyBok();
        
        bok = b;
    }

    public double obwod() {
        return 6 * bok;
    }

    public double pole() {
        return (3 * bok * bok * Math.sqrt(3)) / 2;
    }
}

abstract class Czworokat extends Figura {
    public static Czworokat rozpoznaj(double bokA, double bokB, double bokC, double bokD, double kat) throws BlednyCzworokat, BlednyBok, BlednyKat {
        if((bokA == bokB) && (bokA == bokC) && (bokA == bokD)) {
            if(kat == 90)
                return new Kwadrat(bokA);
            return new Romb(bokA, kat);
        }
        if((((bokA == bokB) && (bokC == bokD)) || ((bokA == bokC) && (bokB == bokD)) || ((bokA == bokD) && (bokB == bokC))) && kat == 90) {
            double a = bokA;
            double b;
            if(bokB == bokA)
                b = bokC;
            else
                b = bokB;
            return new Prostokat(a, b);
        }

        throw new BlednyCzworokat();
    }
}

class Kwadrat extends Czworokat {
    private double bok;

    public Kwadrat(double b) throws BlednyBok {
        if(b <= 0)
            throw new BlednyBok();
        
        bok = b;
    }

    public double obwod() {
        return 4 * bok;
    }

    public double pole() {
        return bok * bok;
    }
}

class Prostokat extends Czworokat {
    private double bokA;
    private double bokB;

    public Prostokat(double a, double b) throws BlednyBok {
        if(a <= 0 || b <= 0)
            throw new BlednyBok();
        
        bokA = a;
        bokB = b;
    }

    public double obwod() {
        return 2 * bokA + 2 * bokB;
    }

    public double pole() {
        return bokA * bokB;
    }
}

class Romb extends Czworokat {
    private double bok;
    private double kat;

    public Romb(double b, double k) throws BlednyBok, BlednyKat {
        if(b <= 0)
            throw new BlednyBok();
        if(k <= 0 || k >= 180)
            throw new BlednyKat(k);
        
        bok = b;
        kat = k;
    }

    public double obwod() {
        return 4 * bok;
    }

    public double pole() {
        return bok * bok * Math.sin(Math.toRadians(kat));
    }
}

class BlednyKat extends Exception {
    public BlednyKat(double k) {
        super("Bledny kat: " + k + ". Kat powinien byc w zakresie (0, 180).");
    }
}

class BlednyCzworokat extends Exception {
    public BlednyCzworokat() {
        super("Brak obslugi czworokata o podanych parametrach.");
    }
}

class BlednyBok extends Exception {
    public BlednyBok() {
        super("Niepoprawna wartosc dlugosci boku.");
    }
}

class BlednaFigura extends Exception {
    public BlednaFigura() {
        super("Brak obsugi danej figury.");
    }
}