#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[4];
int n, a;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == 1) {
      dp[0]++;
      dp[2] = max(dp[2] + 1, dp[1] + 1);
    } else {
      dp[1] = max(dp[1] + 1, dp[0] + 1);
      dp[3] = max(dp[3] + 1, dp[2] + 1);
    }
  }
  cout << *max_element(dp, dp + 4) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}