#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926536
#define ll int64_t
#define INF INT64_MAX
const int N = 1e6 + 5;
struct {
  int x, y;
} P[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, x0, y0, x, y;
  double minn = INF, maxx = 0;
  cin >> n >> x0 >> y0;
  for (int i = 0; i < n; i++) {
    cin >> P[i].x >> P[i].y;
  }
  for (int i = 0; i < n; i++) {
    int x1 = P[i].x, y1 = P[i].y;
    double d = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    maxx = max(maxx, d);
    minn = min(minn, d);
    int x2 = P[(i + 1) % n].x, y2 = P[(i + 1) % n].y;
    double v1 = (y2 - y0) * (y2 - y1) + (x2 - x0) * (x2 - x1);
    double v2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (v1 >= 0 && v1 <= v2) {
      double a = abs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
      minn = min(minn, a * a / v2);
    }
  }
  cout.precision(7);
  cout << fixed << pi * (maxx - minn);
  return 0;
}