#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct point {
  int x, y;
} P[N], a, b, t;
int n;
double dp[4];
double getDist(const point& p1, const point& p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
void solve() {
  cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
  cin >> n;
  int x, y;
  double d = 0;
  dp[1] = dp[2] = dp[3] = -1e16;
  for (int i = 0; i < n; i++) {
    cin >> P[i].x >> P[i].y;
    double da = getDist(a, P[i]), db = getDist(b, P[i]), dt = getDist(t, P[i]);
    d += 2.0 * dt;
    dp[3] = max(dp[3], max(dp[1] + dt - db, dp[2] + dt - da));
    dp[1] = max(dp[1], dt - da);
    dp[2] = max(dp[2], dt - db);
  }
  cout.precision(7);
  cout << fixed << (d - max(dp[3], max(dp[1], dp[2]))) << "\n";
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}