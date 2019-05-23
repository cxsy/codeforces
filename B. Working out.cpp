#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1005;
int A[N][N]; 
ll dp[4][N][N];
int n, m;
void build() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
    }
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + A[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j + 1]) + A[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j - 1]) + A[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp[3][i][j] = max(dp[3][i - 1][j], dp[3][i][j + 1]) + A[i][j];
    }
  }
  ll sol = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      ll cnt1 = dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1];
      ll cnt2 = dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j];
      sol = max(sol, max(cnt1, cnt2));
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}