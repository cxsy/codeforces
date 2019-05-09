#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 2005, MOD = 1e9 + 7;
unordered_map<int, unordered_set<int>> mm;
int main(int argc, char const *argv[]) {
  int n, e, k, v1, v2;
  cin >> n >> e >> k;
  for (int i = 0; i < k; i++) cin >> v1 >> v2, mm[v1].insert(v2);
  int r = 1 << (2 * e + 1);
  vector<ll> dp(r), temp(r);
  fill(dp.begin(), dp.end(), 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    fill(temp.begin(), temp.end(), 0);
    for (int s = 0; s < r; s++) {
      int ne = s >> 1;
      if (__builtin_popcount(ne) != min(i - 1, e)) continue;
      for (int j = -e; j <= e; j++) {
        int ad = 1 << (j + e);
        if (!mm[i].count(i + j) && (ne & ad) == 0) {
          temp[ne | ad] = (temp[ne | ad] + dp[s]) % MOD;
        }
      }
    }
    dp = temp;
  }
  cout << dp[(r - 1) >> e] << "\n";
  return 0;
}