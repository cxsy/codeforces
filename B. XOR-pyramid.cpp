
#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N][N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dp[0][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
    }
  }
  int q, l, r;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    l--;
    cout << dp[r - l - 1][l] << "\n";
  }
  return 0;
}