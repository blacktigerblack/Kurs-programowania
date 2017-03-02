public class Program {
    public static void main(String[] args) {
        int n;
        for(int i = 0; i < args.length; i++) {
            try {
                n = Integer.parseInt(args[i]);
                System.out.println(n + ": " + div(n));
            }
            catch(NumberFormatException ex) {
                System.out.println(args[i] + " nie jest liczba calkowita");
            }
        }
    }

    public static int div(int n) {
        return n;
    }
}
