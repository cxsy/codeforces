#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int NINF = -1e8;
int n, m, C[N], dp[N][N];
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }
  sort(C, C + n, greater<int>());
  fill(&dp[0][0], &dp[0][0] + N * N, NINF);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int d = i + 1; d >= 1; d--) {
      for (int c = i + 1; c >= 2; c--) {
        dp[d][c] = max(dp[d][c], dp[d][c - 1] + max(0, C[i] - c + 1));
      }
      for (int c = i; c >= 0; c--) {
        dp[d][1] = max(dp[d][1], dp[d - 1][c] + C[i]);
      }
    }
  }
  for (int d = 1; d <= n; d++) {
    for (int c = 1; c <= n; c++) {
      if (dp[d][c] >= m) {
        cout << d << "\n";
        exit(0);
      }
    }
  }
  cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}