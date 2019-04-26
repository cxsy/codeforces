#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

const int NMAX = 18;
ll di[NMAX + 1];
ll bo[NMAX + 1][NMAX + 1];
ll dp[1 << NMAX][NMAX + 1];
int n, m, k;

ll dfs(int st, int co, int pre);

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  fill(&dp[0][0], &dp[0][0] + (1 << NMAX) * (NMAX + 1), -1);
  for (int i = 1; i <= n; i++) {
    cin >> di[i];
  }
  int x, y, b;
  for (int i = 0; i < k; i++) {
    cin >> x >> y >> b;
    bo[x][y] = b;
  }
  cout << dfs(0, 0, 0) << "\n";
  return 0;
}

ll dfs(int st, int co, int pre) {
  if (dp[st][pre] >= 0) return dp[st][pre];
  if (co == m) return 0;
  ll maxx = -1;
  for (int i = 1; i <= n; i++) {
    if ((st & (1 << (i - 1))) > 0) continue;
    maxx = max(maxx, bo[pre][i] + di[i] + dfs(st | (1 << (i - 1)), co + 1, i));
  }
  dp[st][pre] = maxx;
  return maxx;
}