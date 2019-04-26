#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

map<double, ii> mm;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, L;
  cin >> n >> L;
  int p;
  for (int i = 0; i < n; i++) {
    cin >> p;
    double ap = (p + 0.0) / (1 << i);
    if (mm.find(ap) == mm.end()) {
      mm[ap] = {1 << i, p};
    }
  }
  int64_t ans = INT64_MAX;
  int64_t cost = 0;
  for (auto &en : mm) {
    int v = en.second.first, p = en.second.second;
    cost += 1LL * L / v * p;
    L %= v;
    ans = min(ans, cost + (L == 0 ? 0 : p));
    if (L == 0) break;
  }
  cout << ans << "\n";
  return 0;
}