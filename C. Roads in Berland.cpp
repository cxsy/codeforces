#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 305;
ll D[N][N];
int n, k;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> D[i][j];
    }
  }
  cin >> k;
  int u, v, w;
  for (int t = 0; t < k; t++) {
    cin >> u >> v >> w;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        D[i][j] = min(D[i][j], D[i][u] + w + D[v][j]);
        D[i][j] = min(D[i][j], D[i][v] + w + D[u][j]);
        D[j][i] = D[i][j];
        tot += D[i][j];
      }
    }
    cout << tot << " ";
  }
  cout << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}