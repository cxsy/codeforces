#include <bits/stdc++.h>
using namespace std;
#define exit(s) cout << s << "\n", exit(0);
const int N = 1e6 + 5;
const int M = 1e3 + 5;
int A[N];
int n, m;
bool dp[2][M];
void solve() {
  cin >> n >> m;
  if (n > m) exit("YES");
  for (int i = 1; i <= n; i++) cin >> A[i];
  int i = 0;
  dp[i][0] = true;
  for (int k = 1; k <= n; k++) {
    for (int r = 0; r < m; r++) {
      int t = (r + A[k]) % m;
      dp[i ^ 1][t] |= dp[i][r];
      if (dp[i ^ 1][t] && t == 0) exit("YES");
    }
    for (int r = 0; r < m; r++) dp[i ^ 1][r] |= dp[i][r];
    fill(&dp[i][0], &dp[i][0] + m, false);
    i ^= 1;
  }
  exit("NO");
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}