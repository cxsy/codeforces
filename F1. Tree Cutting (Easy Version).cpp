#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int A[N];
bool vis[N];
vector<int> nei[N];
int n, cntr, cntb, sol;
vector<int> dfs(int r) {
  vis[r] = true;
  vector<int> ret{0, 0};
  if (A[r] == 1) ret[0]++;
  if (A[r] == 2) ret[1]++;
  for (int i : nei[r]) {
    if (!vis[i]) {
      vector<int> v = dfs(i);
      if (v[0] == cntr && v[1] == 0) sol++;
      if (v[0] == 0 && v[1] == cntb) sol++;
      ret[0] += v[0];
      ret[1] += v[1];
    }
  }
  return ret;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (A[i] == 1) cntr++;
    if (A[i] == 2) cntb++;
  }
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    nei[u].emplace_back(v);
    nei[v].emplace_back(u);
  }
  dfs(1);
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}