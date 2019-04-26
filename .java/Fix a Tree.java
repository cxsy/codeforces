import java.util.*;

public class Solution {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] arr = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      arr[i] = in.nextInt();
    }
    for (int i = 1; i <= n; i++) {
      setRoot(arr, i);
    }
    int ans = 0, root = -1;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == i) {
        if (root == -1) {
          root = i;
        } else {
          arr[i] = root;
        }
        ans++;
      }
    }
    System.out.println(ans - 1);
    for (int i = 1; i <= n; i++) {
      System.out.println(arr[i] + (i == n ? "\n" : " "));
    }
  }

  static void setRoot(int[] arr, int num) {
    Set<Integer> set = new HashSet<>();
    int root = num;
    while (root != arr[root]) {
      set.add(root);
      root = arr[root];
      if (set.contains(root)) {
        arr[root] = root;
        break;
      }
    }
    while (num != root) {
      int tmp = arr[num];
      arr[num] = root;
      num = tmp;
    }
  }
}