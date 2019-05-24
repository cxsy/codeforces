#include <bits/stdc++.h>
using namespace std;
struct node {
  node* ch[2];
  int cnt;
}* Trie = new node();
int q, x;
char c;
void add(int x) {
  bitset<30> b(x);
  node* cur = Trie;
  for (int i = 29; i >= 0; i--) {
    if (!cur->ch[b[i]]) {
      cur->ch[b[i]] = new node();
    }
    cur = cur->ch[b[i]];
    cur->cnt++;
  }
}
void del(int x) {
  bitset<30> b(x);
  node* cur = Trie;
  for (int i = 29; i >= 0; i--) {
    cur = cur->ch[b[i]];
    cur->cnt--;
  }
  int get(int x) {
    bitset<30> b(x);
    node* cur = Trie;
    int ret = 0;
    for (int i = 29; i >= 0; i--) {
      if (cur->ch[b[i] ^ 1] && cur->ch[b[i] ^ 1]->cnt) {
        cur = cur->ch[b[i] ^ 1];
        ret |= (1 << i);
      } else {
        cur = cur->ch[b[i]];
      }
    }
    return ret;
  }
  void deal() {
    cin >> q;
    add(0);
    for (int i = 0; i < q; i++) {
      cin >> c >> x;
      if (c == '+') add(x);
      if (c == '-') del(x);
      if (c == '?') cout << get(x) << "\n";
    }
  }
  int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deal();
    return 0;
  }