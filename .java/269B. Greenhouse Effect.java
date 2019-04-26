import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    in.next();
    double[] plants = new double[N];
    for (int i = 0; i < N; i++) {
      plants[i] = in.nextDouble() + (i + 0.0) / N;
      in.next();
    }
    List<Double> list = new ArrayList<>();
    for (double p : plants) {
      int index = Collections.binarySearch(list, p);
      index = index < 0 ? -index - 1 : index;
      if (index == list.size()) {
        list.add(p);
      } else {
        list.set(index, p);
      }
    }
    System.out.println(N - list.size());
  }
}