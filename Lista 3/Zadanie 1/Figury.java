public class Figury {
    public enum K1 {
        Okrag {
            public double obliczPole(double r) throws BladArgument {
                if(r <= 0)
                    throw new BladArgument();
                return 2 * Math.PI * r;
            }

            public double obliczObwod(double r) throws BladArgument {
                if(r <= 0)
                    throw new BladArgument();
                return 2 * Math.PI * r;
            }
        },
        Kwadrat {
            public double obliczPole(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return a * a;
            }

            public double obliczObwod(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return 4 * a;
            }
        },
        Pieciokat {
            public double obliczPole(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return (a * a * Math.sqrt(5 * (5 + 2 * Math.sqrt(5)))) / 4;
            }

            public double obliczObwod(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return 5 * a;
            }
        },
        Szesciokat {
            public double obliczPole(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return (3 * a * a * Math.sqrt(3)) / 2;
            }

            public double obliczObwod(double a) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return 6 * a;
            }
        };

        public abstract double obliczPole(double a) throws BladArgument;
        public abstract double obliczObwod(double a) throws BladArgument;
    }

    public enum K2 {
        Prostokat {
            public double obliczPole(double a, double b) throws BladArgument {
                if(a <= 0 || b <= 0)
                    throw new BladArgument();
                return a * b;
            }

            public double obliczObwod(double a, double b) throws BladArgument {
                if(a <= 0 || b <= 0)
                    throw new BladArgument();
                return (2 * a) + (2 * b);
            }
        },
        Romb {
            public double obliczPole(double a, double k) throws BladArgument {
                if(a <= 0 || k <= 0 || k >= 180)
                    throw new BladArgument();
                return a * a * Math.sin(Math.toRadians(k));
            }

            public double obliczObwod(double a, double k) throws BladArgument {
                if(a <= 0)
                    throw new BladArgument();
                return 4 * a;
            }
        };

        public abstract double obliczPole(double a, double b) throws BladArgument;
        public abstract double obliczObwod(double a, double b) throws BladArgument;   
    }
}



class Blad extends Exception {
    public Blad(String blad) {
        super(blad);
    }
}

class BladArgument extends Blad {
    public BladArgument() {
        super("Bledny argument.");
    }
}

class BladFigura extends Blad {
    public BladFigura() {
        super("Brak obsugi danej figury.");
    }
}