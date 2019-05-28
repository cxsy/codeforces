#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e5 + 5;
const ll INF = 1e18;
ll dp[N][5];
char s[N], h[5] = "hard";
int n;
void solve() {
  cin >> n >> s;
  int a;
  fill(&dp[0][0], &dp[0][0] + N * 5, INF);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 0; j < 4; j++) {
      if (s[i] == h[j]) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
      } else {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      }
    }
  }
  cout << *min_element(dp[n], dp[n] + 4) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}