#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int n, l, v1, v2, k;
int gp;
bool test(double t) {
  double onbus = (l - v1 * t) / (v2 - v1);
  if (onbus <= 0.0) return true;
  double re = (l - v1 * t) / (v2 + v1);
  return onbus * gp + re * (gp - 1) <= t;
}
void build() {
  cin >> n >> l >> v1 >> v2 >> k;
  gp = (n + k - 1) / k;
}
void solve() {
  double l = 0.0, h = 1e9;
  while (cnt < 100) {
    double mid = (l + h) / 2.0;
    if (test(mid)) {
      h = mid;
    } else {
      l = mid;
    }
    cnt++;
  }
  cout.precision(7);
  cout << fixed << h << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}