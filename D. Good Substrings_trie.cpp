#include <bits/stdc++.h>
using namespace std;
struct node {
  node* ch[26];
}* Trie = new node();
string s;
char J[26];
int k;
void build() { cin >> s >> J >> k; }
void solve() {
  int len = s.size(), sol = 0;
  for (int i = 0; i < len; i++) {
    node* cur = Trie;
    int bcnt = 0;
    for (int j = i; j < len; j++) {
      int c = s[j] - 'a';
      bcnt += J[c] == '0';
      if (bcnt > k) break;
      if (!cur->ch[c]) {
        cur->ch[c] = new node();
        sol++;
      }
      cur = cur->ch[c];
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}