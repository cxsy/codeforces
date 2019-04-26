
#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<int> v;
int minn = 0;
int dp[N][N][2];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, pre = -1, val;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val != pre) {
      v.push_back(val);
    }
    pre = val;
  }
  int size = v.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      dp[i][j][0] = dp[i][j][1] = i == j ? 0 : N;
    }
  }
  for (int r = 1; r < size; r++) {
    for (int l = r - 1; l >= 0; l--) {
      for (int t = 0; t <= 1; t++) {
        dp[l][r][0] =
            min(dp[l][r][0],
                dp[l + 1][r][t] + (int)(v[l] != (t == 0 ? v[l + 1] : v[r])));
        dp[l][r][1] =
            min(dp[l][r][1],
                dp[l][r - 1][t] + (int)(v[r] != (t == 0 ? v[l] : v[r - 1])));
      }
    }
  }
  cout << min(dp[0][size - 1][0], dp[0][size - 1][1]) << "\n";
  return 0;
}