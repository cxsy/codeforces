import java.util.*;

class Solution {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String s = in.next();
    Trie root = new Trie();
    long ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      root.addWord(s.substring(i), i);
    }
    s = new StringBuilder(s).reverse().toString();
    for (int i = 0; i < len; i++) {
      ans += root.searchWord(s.substring(i), len - 1 - i);
    //   System.out.println(ans);
    }
    System.out.println(ans);

  }

  static private boolean isPalindrome(char[] chArr, int l, int r) {
    while (l < r && chArr[l] == chArr[r]) {
      l++;
      r--;
    }
    return l >= r;
  }

  static class Trie {
    node root;

    Trie() {
      this.root = new node();
    }

    public void addWord(String word, int start) {
      node cur = root;
      char[] chArr = word.toCharArray();
      for (int i = 0; i < chArr.length; i++) {
        char ch = chArr[i];
        if (cur.child[ch - 'a'] == null) {
          cur.child[ch - 'a'] = new node();
        }
        cur = cur.child[ch - 'a'];
        for (int j = i + 1; j < chArr.length; j++) {
          if (isPalindrome(chArr, i + 1, j)) {
            cur.pal.add(start + j);
          }
        }
        cur.list.add(start + i);
      }
    }

    public int searchWord(String word, int end) {
      int ans = 0;
      node cur = root;
      char[] chArr = word.toCharArray();
      for (int i = 0; i < chArr.length; i++) {
        char ch = chArr[i];
        if (cur.child[ch - 'a'] == null) {
          return ans;
        }
        cur = cur.child[ch - 'a'];
        for (int j = i; j < chArr.length; j++) {
          if (isPalindrome(chArr, i + 1, j)) {
            int index = Collections.binarySearch(cur.list, end - j);
            index = index >= 0 ? index : -index - 1;
            ans += index;
            // System.out.println("** " + ans);
          }
        }
        for (int p : cur.pal) {
            if (p < end - i) {
                ans++;
            }
        }
      }
     return ans;
    }
  }

  static class node {
    List<Integer> list; // list of end indexs of substrings which end at this node
    List<Integer> pal; // list of end indexs of substrings whose suffix is palindrome
    node[] child;

    node() {
      list = new ArrayList<>();
      pal = new ArrayList<>();
      child = new node[26];
    }
  }
}