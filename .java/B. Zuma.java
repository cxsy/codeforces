import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] gs = new int[N];
        for (int i = 0; i < N; i++) {
            gs[i] = in.nextInt();
        }
        int[][] dp = new int[N][N];
        for (int d = 0; d < N; d++) {
            for (int i = 0; i < N - d; i++) {
                int j = i + d;
                int left = i, right = j;
                while (left < right && gs[left] == gs[right]) {
                    left++;
                    right--;
                }
                if (left >= right) {
                    dp[i][j] = 1;
                } else {
                    int tmp = Integer.MAX_VALUE;
                    for (int k = j; k >= i; k--) {
                        if (gs[k] == gs[j]) {
                            tmp = Math.min(tmp, (k == i ? 0 : dp[i][k - 1]) + (k >= j - 1 ? 1 : dp[k + 1][j - 1]));
                        }
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        System.out.println(dp[0][N - 1]);
    }
}