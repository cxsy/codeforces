#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
vector<int> vi, cnt, dp;
vector<vector<int>> comb;
string s;
int k;
void solve() {
  cin >> s >> k;
  int n = s.size();
  if (k == 0) {
    cout << 1 << "\n";
    exit(0);
  }
  vi.resize(n + 5);
  cnt.resize(n + 5, 0);
  dp.resize(n + 5, 0);
  comb.resize(n + 5, vector<int>(n + 5, 0));
  dp[1] = -1;
  set<int> ss;
  for (int i = 1; i < n + 5; i++) {
    bitset<16> b(i);
    dp[i] = dp[b.count()] + 1;
    if (dp[i] == k - 1) {
      ss.insert(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cnt[i] = i == 0 ? s[i] - '0' : cnt[i - 1] + s[i] - '0';
  }
  comb[0][0] = 1;
  for (int i = 1; i < n + 5; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = (0ll + comb[i - 1][j - 1] + comb[i - 1][j]) % m;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      for (int k = 0; k < n - i; k++) {
        int t = (i == 0 ? 0 : cnt[i - 1]) + k;
        vi[t] = (0ll + vi[t] + comb[n - i - 1][k]) % m;
      }
    }
  }
  vi[cnt[n - 1]]++;
  int sol = k == 1 ? m - 1 : 0;
  for (int t : ss) {
    sol = (0ll + sol + vi[t]) % m;
  }
  cout << sol << '\n';
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}