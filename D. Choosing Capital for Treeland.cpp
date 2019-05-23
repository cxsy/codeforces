#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
unordered_map<int, unordered_set<int>> nei;
unordered_map<int, unordered_set<int>> ch;
bool vis[N];
int n, minn;
vector<int> sol;
void build() {
  cin >> n;
  int s, t;
  for (int i = 0; i < n - 1; i++) {
    cin >> s >> t;
    nei[s].insert(t);
    nei[t].insert(-s);
  }
}
int helper1(int r) {
  vis[r] = true;
  int ret = 0;
  for (int to : nei[r]) {
    if (!vis[abs(to)]) {
      vis[abs(to)] = true;
      ch[r].insert(abs(to));
      ret += int(to < 0) + helper1(abs(to));
    }
  }
  return ret;
}
void helper2(int r, int p) {
  for (int c : ch[r]) {
    int t = nei[r].count(-c) ? p - 1 : p + 1;
    if (minn > t) {
      minn = t;
      sol.clear();
      sol.emplace_back(c);
    } else if (minn == t) {
      sol.emplace_back(c);
    }
    helper2(c, t);
  }
}
void solve() {
  minn = helper1(1);
  sol.emplace_back(1);
  helper2(1, minn);
  cout << minn << "\n";
  sort(sol.begin(), sol.end());
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i] << " \n"[i == sol.size() - 1];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}