#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 2e5 + 5;
const ll NINF = -1e17;
ll A[N];
vector<vector<int>> nei(N);
bool vis[N];
int n;
ll sol = NINF;
ll dfs(int i, ll& sum) {
  vis[i] = true;
  ll max1 = NINF, max2 = NINF;
  for (int j : nei[i]) {
    if (!vis[j]) {
      vis[j] = true;
      ll ss = 0;
      ll v = dfs(j, ss);
      sum += ss;
      if (v > max1) {
        max2 = max1;
        max1 = v;
      } else if (v > max2) {
        max2 = v;
      }
    }
  }
  if (max1 > NINF && max2 > NINF) {
    sol = max(sol, max1 + max2);
  }
  sum += A[i];
  return max(sum, max1);
}
void solve() {
  cin >> n;
  nei.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    nei[u].emplace_back(v);
    nei[v].emplace_back(u);
  }
  ll sum = 0;
  dfs(1, sum);
  if (sol > NINF) {
    cout << sol << "\n";
  } else {
    cout << "Impossible\n";
  }
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}