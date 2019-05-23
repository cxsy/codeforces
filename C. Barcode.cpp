#include <bits/stdc++.h>
using namespace std;
#define INF 1e6 + 5
const int N = 1e3 + 5;
char A[N][N];
int dp[2][N], dpt[2][N];
int n, m, x, y;
void build() {
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
}
void solve() {
  for (int j = 0; j < m; j++) {
    int cntw = 0;
    fill(&dpt[0][0], &dpt[0][0] + 2 * N, INF);
    for (int i = 0; i < n; i++) cntw += int(A[i][j] == '.');
    int cntb = n - cntw;
    if (j == 0) {
      dpt[0][1] = cntw;
      dpt[1][1] = cntb;
    } else {
      for (int k = x; k <= y; k++) {
        dpt[0][1] = min(dpt[0][1], dp[1][k] + cntw);
        dpt[1][1] = min(dpt[1][1], dp[0][k] + cntb);
      }
      for (int k = 1; k < y; k++) {
        dpt[0][k + 1] = min(dpt[0][k + 1], dp[0][k] + cntw);
        dpt[1][k + 1] = min(dpt[1][k + 1], dp[1][k] + cntb);
      }
    }
    copy(&dpt[0][0], &dpt[0][0] + 2 * N, &dp[0][0]);
  }
  int sol = INF;
  for (int k = x; k <= y; k++) {
    sol = min(sol, min(dp[0][k], dp[1][k]));
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