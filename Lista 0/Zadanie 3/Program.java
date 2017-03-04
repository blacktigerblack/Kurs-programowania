public class Program {
    public static void main(String[] args) {
        int n;
        for(int i = 0; i < args.length; i++) {
            try {
                n = Integer.parseInt(args[i]);
                if(n <= 0)
                    throw new NumberFormatException();
                System.out.println(n + ": " + div(n));
            }
            catch(NumberFormatException ex) {
                System.out.println(args[i] + " nie jest liczba naturalna");
            }
        }
    }

    public static int div(int n) {
        int d = 1;
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0)
                d = i;
        }
        return d;
    }
}

