#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int dp[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    dp[i + 1] = int((0LL + 2 * dp[i] - dp[p] + 2) % MOD);
  }
  cout << (dp[n + 1] + MOD) % MOD << "\n";
  return 0;
}