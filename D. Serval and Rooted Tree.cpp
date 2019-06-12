#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int op[N];
vector<int> ch[N];
int n, k, p;
int dfs(int r) {
  vector<int> v;
  for (int c : ch[r]) {
    v.emplace_back(dfs(c));
  }
  if (v.empty()) {
    k++;
    return 1;
  }
  if (op[r] == 0) {
    return accumulate(v.begin(), v.end(), 0);
  } else {
    return *min_element(v.begin(), v.end());
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> op[i];
  for (int i = 2; i <= n; i++) {
    cin >> p;
    ch[p].emplace_back(i);
  }
  int m = dfs(1);
  cout << (k - m + 1) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}