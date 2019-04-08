import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[][] arr = new int[N][N];
        int zr = -1;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                arr[r][c] = in.nextInt();
                if (arr[r][c] == 0) {
                    arr[r][c] = 10;
                    zr = r;
                }
            }
        }
        node n2 = helper(2, arr);
        node n5 = helper(5, arr);
        if (zr != -1 && n2.num > 0 && n5.num > 0) {
            StringBuilder sb = new StringBuilder();
            for (int r = 0; r < zr; r++) {
                sb.append('D');
            }
            for (int c = 0; c < N - 1; c++) {
                sb.append('R');
            }
            for (int r = zr; r < N - 1; r++) {
                sb.append('D');
            }
            System.out.println(1);
            System.out.println(sb.toString());
        } else {
            System.out.println(Math.min(n2.num, n5.num));
            System.out.println(n2.num <= n5.num ? n2.path : n5.path);
        }
    }

    static public node helper(int p, int[][] arr) {
        int N = arr.length;
        int[] dp = new int[N];
        char[][] dir = new char[N][N];
        for (int r = 0; r < N; r++) {
            int[] copy = dp.clone();
            for (int c = 0; c < N; c++) {
                int f = 0;
                while (arr[r][c] % p == 0) {
                    f++;
                    arr[r][c] /= p;
                }
                if (r == 0 && c == 0) {
                    copy[0] = f;
                } else {
                    int left = c == 0 ? Integer.MAX_VALUE : copy[c - 1];
                    int up = r == 0 ? Integer.MAX_VALUE : dp[c];
                    copy[c] = f + Math.min(left, up);
                    dir[r][c] = left <= up ? 'R' : 'D';
                }
            }
            dp = copy;
        }
        int er = N - 1, ec = N - 1;
        StringBuilder sb = new StringBuilder();
        while (er > 0 || ec > 0) {
            char d = dir[er][ec];
            sb.insert(0, d);
            er = d == 'D' ? er - 1 : er;
            ec = d == 'R' ? ec - 1 : ec;
        }
        return new node(sb.toString(), dp[N - 1]);
    }

    static class node {
        String path;
        int num;

        node(String path, int num) {
            this.path = path;
            this.num = num;
        }
    }
}