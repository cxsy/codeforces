#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp(int t) {
  if (t == 0) {
    return {{1}};
  }
  vector<vector<int>> p = dp(t - 1);
  vector<vector<int>> ret(1 << t, vector<int>(1 << t));
  for (int i = 0; i < 1 << (t - 1); i++) {
    for (int j = 0; j < 1 << t; j++) {
      ret[i][j] = p[i][j % (1 << (t - 1))];
    }
  }
  for (int i = 1 << (t - 1); i < 1 << t; i++) {
    for (int j = 0; j < 1 << t; j++) {
      ret[i][j] = j < (1 << (t - 1)) ? p[i % (1 << (t - 1))][j % (1 << (t - 1))]
                                     : -p[i % (1 << (t - 1))][j % (1 << (t - 1))];
    }
  }
  return ret;
}
void solve() {
  cin >> n;
  vector<vector<int>> sol = dp(n);
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      cout << (sol[i][j] == 1 ? '+' : '*');
    }
    cout << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}