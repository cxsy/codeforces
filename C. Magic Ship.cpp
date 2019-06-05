#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e5 + 5;
const int di[4][2]{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int dx[N], dy[N];
string s;
int x1, y1, x2, y2, n;
bool test(ll v) {
  ll ddx = (v / n) * dx[n] + dx[v % n];
  ll ddy = (v / n) * dy[n] + dy[v % n];
  ll xx1 = x1 + ddx, yy1 = y1 + ddy;
  return abs(xx1 - x2) + abs(yy1 - y2) <= v;
}
void solve() {
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    int d;
    if (s[i - 1] == 'U') d = 0;
    if (s[i - 1] == 'D') d = 1;
    if (s[i - 1] == 'L') d = 2;
    if (s[i - 1] == 'R') d = 3;
    dx[i] = dx[i - 1] + di[d][0];
    dy[i] = dy[i - 1] + di[d][1];
  }
  ll l = 1, h = 1e18;
  while (l <= h) {
    ll mid = (l + h) >> 1;
    if (test(mid)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  h++;
  cout << (h > 1e18 ? -1 : h) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}