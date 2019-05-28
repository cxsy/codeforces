#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll a, b;
void solve() {
  cin >> a >> b;
  int diff = abs(a - b);
  vector<int> v;
  for (int i = 1; i * i <= diff; i++) {
    if (diff % i == 0) {
      v.emplace_back(i);
      if (i * i != diff) {
        v.emplace_back(diff / i);
      }
    }
  }
  sort(v.begin(), v.end());
  ll ans = 1e18, sol = 0;
  for (int di : v) {
    int k = (di - (b % di)) % di;
    ll cnd = (a + k) * (b + k) / __gcd(a + k, b + k);
    if (cnd < ans) {
      ans = cnd;
      sol = k;
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}