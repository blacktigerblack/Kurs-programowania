public class Test {
    public static void main(String[] args) {
        try {
            WierszTrojkataPascala wierszTrojkata = new WierszTrojkataPascala(Integer.parseInt(args[0]));

            for(int i = 1; i < args.length; i++) {
                try {
                    System.out.println(wierszTrojkata.wspolczynnik(Integer.parseInt(args[i])));
                }
                catch(BlednyArgumentMetody ex) {
                    System.out.println(ex);
                }
            }
        }
        catch(NumberFormatException ex) {
            System.out.println("Argument nie jest liczba naturalna.");
        }
        catch(BlednyArgumentKonstruktora ex) {
            System.out.println(ex);
        }
        catch(ArrayIndexOutOfBoundsException ex) {
            System.out.println("Niepoprawna ilosc argumentow.");
        }
    }
}