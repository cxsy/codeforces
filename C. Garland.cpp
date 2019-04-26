#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 5;
int t[NMAX], ans[2];
int root = 0, ts = 0, cc = 0;
bool flag = false;
vector<vector<int>> child(NMAX);

int dfs(int rt) {
  int sum = t[rt];
  for (int c : child[rt]) {
    sum += dfs(c);
    if (flag) return 0;
  }
  if (rt != root && sum == ts) {
    ans[cc++] = rt;
    if (cc == 2) flag = true;
    return 0;
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p >> t[i];
    child[p].push_back(i);
    ts += t[i];
  }
  if (ts % 3 != 0) {
    cout << -1 << "\n";
    return 0;
  }
  ts /= 3;
  root = child[0][0];
  dfs(root);
  if (cc < 2)
    cout << -1 << "\n";
  else
    cout << ans[0] << " " << ans[1] << "\n";
  return 0;
}