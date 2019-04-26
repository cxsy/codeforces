import java.util.*;

class Solution {
  public TreeNode recoverFromPreorder(String S) {
    Stack<TreeNode> stack = new Stack<>();
    int i = 0;
    while (i < S.length()) {
      int level = 0;
      String val = "";
      while (i < S.length() && S.charAt(i) == '-') {
        level++;
        i++;
      }
      while (i < S.length() && S.charAt(i) != '-') {
        val += S.charAt(i);
        i++;
      }
      TreeNode node = new TreeNode(Integer.valueOf(val));
      while (stack.size() > level) {
        stack.pop();
      }
      if (stack.size() > 0 && stack.peek().left == null) {
        stack.peek().left = node;
      } else if (stack.size() > 0) {
        stack.peek().right = node;
      }
      stack.push(node);
    }
    return stack.firstElement();
  }
}