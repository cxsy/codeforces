#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int mod = 1e9 + 7;
ll n, m, k;
ll binpow(ll a, ll b) {
  a %= mod;
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  cin >> n >> m >> k;
  if (n % 2 != m % 2 && k == -1) {
    cout << "0\n";
    exit(0);
  }
  cout << binpow(binpow(2, n - 1), m - 1) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}