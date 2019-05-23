#include <bits/stdc++.h>
using namespace std;
#define exit(s) cout << s << "\n", exit(0)
#define ll int64_t
const int N = 2005;
const int INF = 1000;
unordered_map<int, unordered_map<int, unordered_set<int>>> sl;
struct {
  int x, y;
} points[N];
int n;
void build() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }
}
void solve() {
  if (n < 3) exit("0");
  ll sol = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    unordered_map<int, unordered_map<int, unordered_set<int>>> tl;
    int x0 = points[i].x, y0 = points[i].y;
    for (int j = i + 1; j < n; j++) {
      int dx = points[j].x - x0, dy = points[j].y - y0;
      if (dx == 0) {
        dy = INF;
      } else if (dy == 0) {
        dx = INF;
      } else {
        if (dx < 0) {
          dx = -dx;
          dy = -dy;
        }
        int gcd = __gcd(dx, abs(dy));
        dx /= gcd;
        dy /= gcd;
      }
      if (sl[dx][dy].count(i)) continue;
      tl[dx][dy].insert(j);
    }
    for (auto e1 : tl) {
      for (auto e2 : e1.second) {
        int s = e2.second.size() + 1;
        sol -= 1ll * s * (s - 1) * (s - 2) / 6;
        sl[e1.first][e2.first].insert(e2.second.begin(), e2.second.end());
      }
    }
  }
  exit(sol);
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}