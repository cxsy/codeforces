#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii pair<int, int>
const int N = 3e5 + 5;
int G[N];
vector<ii> E[N];
bool vis[N];
int n;
ll sol = 0;
ll dfs(int r) {
  vis[r] = true;
  ll max1 = 0, max2 = 0;
  for (ii e : E[r]) {
    int to = e.first, w = e.second;
    if (!vis[to]) {
      vis[to] = true;
      ll t = dfs(to) - w;
      if (t > max1) {
        max2 = max1;
        max1 = t;
      } else if (t > max2) {
        max2 = t;
      }
    }
  }
  sol = max(sol, max1 + max2 + G[r]);
  return G[r] + max1;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> G[i];
  }
  int u, v, c;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v >> c;
    E[u].emplace_back(ii{v, c});
    E[v].emplace_back(ii{u, c});
  }
  dfs(1);
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}