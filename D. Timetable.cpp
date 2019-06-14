#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> f;
vector<int> dp;
void solve() {
  cin >> n >> m >> k;
  f.resize(n);
  dp.resize(k + 1, 0);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') f[i].emplace_back(j);
    }
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int cnt = f[i].size();
    if (cnt) {
      vector<int> t(cnt + 1, 0);
      t[cnt] = f[i][cnt - 1] - f[i][0] + 1;
      tot += t[cnt];
      for (int j = 1; j < cnt; j++) {
        for (int l = 0; l <= j; l++) {
          t[j] = max(t[j], t[cnt] - (f[i][cnt - 1 - (j - l)] - f[i][l] + 1));
        }
      }
      for (int j = k; j >= 0; j--) {
        for (int l = 0; l <= min(cnt, j); l++) {
          dp[j] = max(dp[j], dp[j - l] + t[l]);
        }
      }
    }
  }
  cout << tot - dp[k] << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}