import java.util.*;

/**
 * B. The least round way
 */
public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[][] arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = in.nextInt();
            }
        }

        int[][] dp = new int[N][31];
        for (int[] r : dp) {
            Arrays.fill(r, Integer.MAX_VALUE);
            r[0] = 0;
        }
        for (int i = 0; i < N; i++) {
            int[][] next = new int[N][31];
            for (int j = 0; j < N; j++) {
                int[] tmp = fact25(arr[i][j]);
                for (int min = 0; min < 31; min++) {
                    
                }
                if (j > 0) {

                }
            }
        }
    }

    private int[] fact25(int num) {

    }
}