#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int cap[N], le[N], ne[N];

int find(int c) { return c == ne[c] ? c : ne[c] = find(ne[c]); }

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cap[i];
    le[i] = cap[i];
    ne[i] = i;
  }
  int m, t, p, x;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t >> p;
    if (t == 1) {
      cin >> x;
      p = find(p);
      while (x > 0) {
        if (le[p] <= x) {
          x -= le[p];
          le[p] = 0;
          if (p == n) break;
          p = ne[p] = find(p + 1);
        } else {
          le[p] -= x;
          break;
        }
      }
    } else {
      cout << cap[p] - le[p] << "\n";
    }
  }
  return 0;
}