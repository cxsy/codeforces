#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int X[N];
int n, m;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> X[i];
  }
  int u, v, c;
  double sol = 0;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> c;
    sol = max(sol, (0.0 + X[u] + X[v]) / c);
  }
  cout.precision(10);
  cout << fixed << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}