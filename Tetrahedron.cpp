#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int dp[4] = {};
  dp[3] = 1;
  for (int i = 0; i < n; i++) {
    int tmp[4];
    for (int p = 0; p < 4; p++) {
      for (int from = 0; from < 4; from++) {
        if (from != p) {
          tmp[p] = (tmp[p] + dp[from]) % mod;
        }
      }
    }
    copy(begin(tmp), end(tmp), dp);
  }
  return dp[3];
  return 0;
}
