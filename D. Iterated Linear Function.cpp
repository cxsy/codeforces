#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int m = 1e9 + 7;
ll binpow(ll a, ll b) {
  ll aa = a % m, ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * aa % m;
    }
    aa = aa * aa % m;
    b >>= 1;
  }
  return ret;
}
ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ll x1, y1;
  ll d = extended_euclidean(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
ll inverse_modular(ll a) {
  ll x, y;
  ll g = extended_euclidean(a, m, x, y);
  x = (x % m + m) % m;
  return x;
}
ll A, B, n, x;
void solve() {
  cin >> A >> B >> n >> x;
  ll n1 = binpow(A, n);
  ll n2 = A == 1 ? n % m : (n1 - 1) * inverse_modular(A - 1) % m;
  ll sol = (n1 * x % m + B * n2 % m) % m;
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}