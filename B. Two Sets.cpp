#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; i++)

const int N = 1e5 + 5;
map<int, int> mm;
int n, a, b, vs[N], p[N], f[N], ss[N];
int find(int c) { return c == f[c] ? c : f[c] = find(f[c]); };
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d%d%d", &n, &a, &b);
  rep(i, 1, n) scanf("%d", p + i), mm[p[i]] = i, f[i] = i;
  rep(i, 1, n) {
    int x = p[i];
    if (mm.count(a - x)) f[find(mm[a - x])] = find(i), vs[i] |= 1;
    if (mm.count(b - x)) f[find(mm[b - x])] = find(i), vs[i] |= 2;
  }
  rep(i, 1, n) ss[i] = 3;
  rep(i, 1, n) ss[find(i)] &= vs[i];
  rep(i, 1, n) if (ss[i] == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  rep(i, 1, n) {
    int s = ss[find(i)];
    cout << ((s & 1) == 0);
    cout << (i == n ? '\n' : ' ');
  }
  return 0;
}