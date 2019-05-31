#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int cnt1[26][26], cnt2[26][26][26];
string s;
bool dp[4][N];
bool eq(int i1, int i2, int len) {
  if (i1 < 0) return false;
  return s.substr(i1, len) == s.substr(i2, len);
}
void solve() {
  cin >> s;
  int sol = 0;
  reverse(s.begin(), s.end());
  dp[2][0] = dp[3][0] = true;
  for (int i = 1; i <= s.size() - 5; i++) {
    if (i >= 2) {
      dp[2][i] = dp[3][i - 2] | (dp[2][i - 2] && !eq(i - 4, i - 2, 2));
      if (dp[2][i] && !cnt1[s[i - 1] - 'a'][s[i - 2] - 'a']) {
        sol++;
        cnt1[s[i - 1] - 'a'][s[i - 2] - 'a'] = 1;
      }
    }
    if (i >= 3) {
      dp[3][i] = dp[2][i - 3] | (dp[3][i - 3] && !eq(i - 6, i - 3, 3));
      if (dp[3][i] && !cnt2[s[i - 1] - 'a'][s[i - 2] - 'a'][s[i - 3] - 'a']) {
        sol++;
        cnt2[s[i - 1] - 'a'][s[i - 2] - 'a'][s[i - 3] - 'a'] = 1;
      }
    }
  }
  cout << sol << "\n";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (cnt1[i][j]) {
        cout << char('a' + i) << char('a' + j) << "\n";
      }
      for (int k = 0; k < 26; k++) {
        if (cnt2[i][j][k]) {
          cout << char('a' + i) << char('a' + j) << char('a' + k) << "\n";
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}