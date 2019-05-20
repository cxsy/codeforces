#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
void solve() {
  cin >> n;
  double v, sol = -n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> v;
    int vi = v;
    if (vi == v) {
      cnt++;
    }
    sol += v - vi;
  }
  double ret = 10000;
  for (int i = max(0, cnt - n); i <= min(n, cnt); i++) {
    ret = min(ret, abs(sol + i));
  }
  cout.precision(3);
  cout << fixed << ret << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}