#include <bits/stdc++.h>
using namespace std;

struct node {
  bool end;
  node* next[3];
}* root = new node();

bool dfs(const string& q, node* cur, int p, int flag);
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    node* cur = root;
    for (int j = 0; j < s.length(); j++) {
      if (!cur->next[s[j] - 'a']) {
        cur->next[s[j] - 'a'] = new node();
      }
      cur = cur->next[s[j] - 'a'];
    }
    cur->end = true;
  }
  string q;
  for (int i = 0; i < m; i++) {
    cin >> q;
    cout << (dfs(q, root, 0, 0) ? "YES" : "NO") << "\n";
  }
  return 0;
}

bool dfs(const string& q, node* cur, int p, int flag) {
  if (!cur) return false;
  if (p == q.length()) {
    return cur->end && flag == 1;
  }
  if (flag == 1) {
    return dfs(q, cur->next[q[p] - 'a'], p + 1, 1);
  }
  bool ans = dfs(q, cur->next[q[p] - 'a'], p + 1, 0);
  for (int i = 0; i <= 2; i++) {
    char ch = 'a' + i;
    if (ch != q[p]) {
      ans |= dfs(q, cur->next[ch - 'a'], p + 1, 1);
    }
  }
  return ans;
}