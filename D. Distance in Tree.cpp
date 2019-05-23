#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 5e4 + 5;
const int K = 505;
int cnt[N][K];
bool vis[N];
int n, k;
ll sol = 0;
unordered_map<int, vector<int>> mm;
void build() {
  cin >> n >> k;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    mm[u].emplace_back(v);
    mm[v].emplace_back(u);
  }
}
void dfs(int r) {
  vis[r] = true;
  for (int nei : mm[r]) {
    if (!vis[nei]) {
      vis[nei] = true;
      dfs(nei);
      for (int t = 0; t < k; t++) {
        sol += 1ll * cnt[nei][t] * cnt[r][k - 1 - t];
      }
      for (int t = 0; t < k; t++) {
        cnt[r][t + 1] += cnt[nei][t];
      }
    }
  }
  sol += cnt[r][k];
  cnt[r][0]++;
}
void solve() {
  dfs(1);
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}