#include <bits/stdc++.h>
using namespace std;
vector<int> A, dp;
map<int, int> st, en;
int n;
void solve() {
  cin >> n;
  A.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (!st[A[i]]) st[A[i]] = i;
    en[A[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (en[A[i]] == i) {
      bool f = true;
      int j = i, k = i;
      set<int> ss;
      while (k >= j) {
        if (en[A[k]] > i) {
          f = false;
          break;
        }
        ss.insert(A[k]);
        j = min(j, st[A[k]]);
        k--;
      }
      if (f) {
        int t = accumulate(ss.begin(), ss.end(), 0,
                           [](int a, int b) { return a ^ b; });
        dp[i] = max(dp[i], dp[k] + t);
      }
    }
  }
  cout << dp[n] << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}