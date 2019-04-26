#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int NMAX = 105, KMAX = 105;
int dp[NMAX][KMAX];

int dfs(int n, int k, int d) {
  if (n == 0) return d == 1 ? 1 : 0;
  if (dp[n][d] != -1) return dp[n][d];
  int ans = 0;
  for (int i = 1; i <= min(k, n); i++) {
    ans = (ans + dfs(n - i, k, i < d ? d : 1)) % mod;
  }
  return dp[n][d] = ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, d;
  cin >> n >> k >> d;
  fill(&dp[0][0], &dp[0][0] + NMAX * KMAX, -1);
  dfs(n, k, d);
  cout << dp[n][d] << "\n";
  return 0;
}