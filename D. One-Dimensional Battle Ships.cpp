#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
const int N = 2e5 + 5;
set<ii> segs;
int n, k, a, m, c[N];
void solve() {
  cin >> n >> k >> a >> m;
  for (int l = 1; l <= n; l++) {
    c[l] = l / (a + 1) + int(l % (a + 1) == a);
  }
  segs.insert(ii{n, 1});
  int sh, tot = c[n];
  for (int i = 1; i <= m; i++) {
    cin >> sh;
    auto it = segs.lower_bound(ii{sh, 0});
    if (it != segs.end() && it->second <= sh) {
      tot += c[sh - it->second] + c[it->first - sh] -
             c[it->first - it->second + 1];
      if (tot < k) {
        cout << i << "\n";
        exit(0);
      }
      if (sh - 1 >= it->second) segs.insert({sh - 1, it->second});
      if (it->first >= sh + 1) segs.insert({it->first, sh + 1});
      segs.erase(it);
    }
  }
  cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}