#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll INF = 1e18;
ll n, a, b;
void solve() {
  cin >> n >> a >> b;
  n *= 6;
  if (a * b < n) {
    int minn = min(a, b), maxx = max(a, b);
    ll sol = INF;
    for (ll i = minn;; i++) {
      ll t = (n + i - 1) / i;
      if (i > t || t < maxx) break;
      if (sol > i * t) {
        sol = i * t;
        a = a >= b ? t : i;
        b = a >= b ? i : t;
      }
    }
  }
  cout << a * b << "\n" << a << " " << b << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}