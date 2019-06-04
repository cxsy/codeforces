#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int mi[N], out[N], d[N][N];
int n, m;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i > j) d[i][j] = j + n - i;
      if (i < j) d[i][j] = j - i;
    }
  }
  int u, v;
  fill(mi, mi + N, N);
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    out[u]++;
    mi[u] = min(mi[u], d[u][v]);
  }
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 1; j <= n; j++) {
      if (out[j]) {
        t = max(t, d[i][j] + (out[j] - 1) * n + mi[j]);
      }
    }
    cout << t << " \n"[i == n];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}