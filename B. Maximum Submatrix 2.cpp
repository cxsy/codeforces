#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N][N], cnt[N];  // the number of continuous ones in the right
char r[N];
int n, m;
void count_sort(int arr[]) {
  fill(cnt, cnt + m + 1, 0);
  for (int i = 0; i < n; i++) {
    cnt[arr[i]]++;
  }
  for (int c = 0, i = 0; c <= m; c++) {
    for (int t = 0; t < cnt[c]; t++) {
      arr[i++] = c;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> r;
    for (int j = m - 1; j >= 0; j--) {
      dp[j][i] = r[j] == '0' ? 0 : 1 + dp[j + 1][i];
    }
  }
  int sol = 0;
  for (int j = 0; j < m; j++) {
    count_sort(dp[j]);
    for (int i = 0; i < n; i++) {
      sol = max(sol, dp[j][i] * (n - i));
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}