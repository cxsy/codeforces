#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<pii> vii;
int n;
double get(pii v1, pii v2) {
  return abs(1ll * v1.first * v2.second - 1ll * v1.second * v2.first) / 2.0;
}
double dist(pii p1, pii p2) {
  return sqrt(1ll * (p1.first - p2.first) * (p1.first - p2.first) +
              1ll * (p1.second - p2.second) * (p1.second - p2.second));
}
void solve() {
  cin >> n;
  vii.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vii[i].first >> vii[i].second;
  }
  double sol = 1e16;
  for (int i = 0; i < n; i++) {
    pii p1 = vii[i], p2 = vii[(i + 1) % n], p3 = vii[(i + 2) % n];
    double area = get(pii{p2.first - p1.first, p2.second - p1.second},
                      pii{p3.first - p1.first, p3.second - p1.second});
    sol = min(sol, area / dist(p1, p3));
  }
  cout.precision(7);
  cout << fixed << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}