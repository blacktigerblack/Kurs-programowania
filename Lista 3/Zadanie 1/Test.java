public class Test {
    public static void main(String[] args) {
        try {
            int pozycja = 1;
            for(int i = 0; i < args[0].length(); i++) {
                switch(args[0].charAt(i)) {
                    case 'o':
                    wypisz(Figury.K1.Okrag, Double.parseDouble(args[pozycja]));
                    pozycja++;
                    break;

                    case 'p':
                    wypisz(Figury.K1.Pieciokat, Double.parseDouble(args[pozycja]));
                    pozycja++;
                    break;

                    case 's':
                    wypisz(Figury.K1.Szesciokat, Double.parseDouble(args[pozycja]));
                    pozycja++;
                    break;

                    case 'k':
                    wypisz(Figury.K1.Kwadrat, Double.parseDouble(args[pozycja]));
                    pozycja++;
                    break;

                    case 'r':
                    wypisz(Figury.K2.Romb, Double.parseDouble(args[pozycja]), Double.parseDouble(args[pozycja+1]));
                    pozycja += 2;
                    break;

                    case 't':
                    wypisz(Figury.K2.Prostokat, Double.parseDouble(args[pozycja]), Double.parseDouble(args[pozycja+1]));
                    pozycja += 2;
                    break;

                    default:
                    throw new BladFigura();
                }
            }
        }
        catch(Blad ex) {
            System.out.println(ex);
        }
        catch(NumberFormatException ex) {
            System.out.println("Argument nie jest liczba.");
        }
        catch(IndexOutOfBoundsException ex) {
            System.out.println("Niepoprawna ilosc argumentow.");
        }
    }

    public static void wypisz(Figury.K1 figura, double a) throws BladArgument {
        System.out.println("Obwod: " + figura.obliczObwod(a));
        System.out.println("Pole: " + figura.obliczPole(a));
    }

    public static void wypisz(Figury.K2 figura, double a, double b) throws BladArgument {
        System.out.println("Obwod: " + figura.obliczObwod(a, b));
        System.out.println("Pole: " + figura.obliczPole(a, b));
    }
}