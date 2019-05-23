#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
map<int, vector<int>> mm;
int D[N], cnt[205];
int n, tot;
void build() {
  cin >> n;
  int l;
  for (int i = 0; i < n; i++) {
    cin >> l;
    mm[l].emplace_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> D[i];
    tot += D[i];
  }
}
void solve() {
  int cur = 0, sol = 1e9;
  for (auto e : mm) {
    int del = 0, cost = 0, s = (int)e.second.size();
    for (int d = 1; d <= 200 && (cur - del) >= s; d++) {
      cost += d * min(cnt[d], cur - del - s + 1);
      del += cnt[d];
    }
    for (int l : e.second) {
      cnt[D[l]]++;
      tot -= D[l];
      cur++;
    }
    sol = min(sol, cost + tot);
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}