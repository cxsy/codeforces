#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ch;
vector<int> cnt;
vector<double> sol;
int n, p;
int dfs1(int r) {
  int counter = 1;
  for (int c : ch[r]) {
    counter += dfs1(c);
  }
  return cnt[r] = counter;
}
void dfs2(int r, double t) {
  sol[r] = t;
  for (int c : ch[r]) {
    dfs2(c, t + (cnt[r] - cnt[c] + 1) / 2.0);
  }
}
void solve() {
  cin >> n;
  ch.resize(n + 1);
  cnt.resize(n + 1);
  sol.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> p;
    ch[p].emplace_back(i);
  }
  dfs1(1);
  dfs2(1, 1.0);
  cout.precision(7);
  for (int i = 1; i <= n; i++) {
    cout << fixed << sol[i] << " \n"[i == n];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}