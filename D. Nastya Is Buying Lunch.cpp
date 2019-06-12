#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int A[N], was[N];
vector<int> g[N];
int n, m, u, v;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].emplace_back(v);
  }
  int cnt = 1, sol = 0;
  was[A[n]] = 1;
  for (int i = n - 1; i >= 1; i--) {
    int cnt2 = 0;
    for (int v : g[A[i]]) {
      if (was[v]) cnt2++;
    }
    if (cnt2 == cnt) {
      sol++;
    } else {
      was[A[i]] = 1;
      cnt++;
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}