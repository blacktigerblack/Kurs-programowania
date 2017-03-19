public class Test {
    public static void main(String[] args) {
        try {
            Figura[] figury = parsuj(args);
            for(Figura f : figury) {
                wypisz(f);
            }
        }
        catch(NumberFormatException ex) {
            System.out.println("Niepoprawny argument.");
        }
        catch(ArrayIndexOutOfBoundsException ex) {
            System.out.println("Niepoprawna ilosc argumentow.");
        }
        catch(BlednaFigura ex) {
            System.out.println(ex);
        }
        catch(BlednyBok ex) {
            System.out.println(ex);
        }
        catch(BlednyKat ex) {
            System.out.println(ex);
        }
        catch(BlednyCzworokat ex) {
            System.out.println(ex);
        }
    }

    public static Figura[] parsuj(String[] args) throws NumberFormatException, ArrayIndexOutOfBoundsException, BlednaFigura, BlednyBok, BlednyKat, BlednyCzworokat {
        Figura[] figury = new Figura[args[0].length()];

        int pozycja = 1;

        for(int i = 0; i < args[0].length(); i++) {
            if(args[0].charAt(i) == 'o') {
                figury[i] = new Okrag(Double.parseDouble(args[pozycja]));
                pozycja++;
            }
            else if(args[0].charAt(i) == 'c') {
                figury[i] = Czworokat.rozpoznaj(Double.parseDouble(args[pozycja]), Double.parseDouble(args[pozycja+1]), Double.parseDouble(args[pozycja+2]), Double.parseDouble(args[pozycja+3]), Double.parseDouble(args[pozycja+4]));
                pozycja += 5;
            }
            else if(args[0].charAt(i) == 'p') {
                figury[i] = new Pieciokat(Double.parseDouble(args[pozycja]));
                pozycja++;
            }
            else if(args[0].charAt(i) == 's') {
                figury[i] = new Szesciokat(Double.parseDouble(args[pozycja]));
                pozycja++;
            }
            else {
                throw new BlednaFigura();
            }
        }
        return figury;
    }
        


    public static void wypisz(Figura f) {
        System.out.println("Obwod: " + f.obwod());
        System.out.println("Pole: " + f.pole());
    }
}