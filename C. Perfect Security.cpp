#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int A[N], P[N];
struct node {
  node *child[2];
  int c;
} *root = new node();
int n;
void build() {
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    node *cur = root;
    for (int s = 29; s >= 0; s--) {
      int bi = (val & (1 << s)) ? 1 : 0;
      if (!cur->child[bi]) cur->child[bi] = new node();
      cur = cur->child[bi];
      cur->c++;
    }
  }
}
int find(int val) {
  node *cur = root;
  for (int s = 29; s >= 0; s--) {
    int bi = (val & (1 << s)) ? 1 : 0;
    cur = (cur->child[bi] && cur->child[bi]->c > 0) ? cur->child[bi]
                                                    : cur->child[bi = 1 ^ bi];
    cur->c--;
    val ^= (bi << s);
  }
  return val;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  build();
  for (int i = 0; i < n; i++) cout << find(A[i]) << (i == n - 1 ? "\n" : " ");
  return 0;
}