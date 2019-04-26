import java.util.*;

class test {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.printf("%7.3f", 1.3210);
  }
  static private int binarySearch(List<Integer> list, int key) {
    int l = 0, h = list.size() - 1;
    while (l <= h) {
      int mid = (h - l) / 2 + l;
      if (list.get(mid) >= key) {
        h = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }

}