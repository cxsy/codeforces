#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int INF = 1e9 + 5;
struct e {
  int to, w;
};
vector<int> sol;
int dp[N][N], p[N][N];
map<int, vector<e>> E;
int n, m, T;
int calc(int i, int j) {
  if (j <= 0) return INF;
  if (dp[i][j] >= 0) return dp[i][j];
  int ret = INF;
  for (e ee : E[i]) {
    int to = ee.to, w = ee.w;
    int cost = calc(to, j - 1) + w;
    if (ret > cost) {
      ret = cost;
      p[j][i] = to;
    }
  }
  return dp[i][j] = ret;
}
void solve() {
  cin >> n >> m >> T;
  int u, v, t;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> t;
    E[v].emplace_back(e{u, t});
  }
  fill(&dp[0][0], &dp[0][0] + N * N, -1);
  dp[1][1] = 0;
  for (int i = n; i >= 2; i--) {
    if (calc(n, i) <= T) {
      cout << i << "\n";
      int t = n, tmp = i;
      while (t) {
        sol.emplace_back(t);
        t = p[tmp][t];
        tmp--;
      }
      for (int j = sol.size() - 1; j >= 0; j--) {
        cout << sol[j] << " \n"[j == 0];
      }
      exit(0);
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}