#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, t;
  double p;
  cin >> n >> p >> t;
  vector<double> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < t; i++) {
    for (int k = i; k >= 0; k--) {
      dp[k + 1] = dp[k] * p;
      dp[k] = dp[k] * (1 - p);
    }
  }
  double ans = 0.0;
  for (int i = 0; i <= min(n, t); i++) {
    ans += dp[i] * i;
  }
  cout << ans << "\n";
  return 0;
}
