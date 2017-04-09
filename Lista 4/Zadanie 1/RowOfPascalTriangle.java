public class RowOfPascalTriangle {

    private int[] row;
    public RowOfPascalTriangle(int n) {
        if(n < 0 || n > 33)
            throw new IllegalArgumentException();
        
        row = new int[n + 1];

        for(int i = 0; i < row.length; i++) {
            row[i] = 1;
            for(int j = i - 1; j > 0; j--) {
                row[j] += row[j-1];
            } 
        }
    }

    public int coefficient(int m) {
        if(m < 0 || m > row.length-1)
            throw new IllegalArgumentException();
        return row[m];
    }
}