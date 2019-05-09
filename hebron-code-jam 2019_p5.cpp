#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool v[N];
vector<vector<int>> nei(N);

int n, k, a;

int dfs(int r) {
  int ret = 1;
  for (int c : nei[r]) {
    if (v[c]) continue;
    v[c] = true;
    ret += dfs(c);
  }
  if (ret == a) {
    k--;
    return 0;
  }
  return ret;
};

int main(int argc, char const *argv[]) {
  cin >> n >> k;
  if (n % k) {
    cout << "NO\n";
    exit(0);
  }
  a = n / k;
  int a1, a2;
  for (int i = 0; i < n; i++) {
    cin >> a1 >> a2;
    nei[a1].emplace_back(a2);
    nei[a2].emplace_back(a1);
  }
  v[1] = true;
  dfs(1);
  cout << (k == 0 ? "YES" : "NO") << "\n";
  return 0;
}