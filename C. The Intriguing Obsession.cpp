#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int m = 998244353;
const int N = 5005;
int P[N][N], F[N], t[3], A[3];
void build() {
  cin >> A[0] >> A[1] >> A[2];
  F[0] = 1;
  for (ll i = 1; i < N; i++) {
    F[i] = 1ll * F[i - 1] * i % m;
  }
  P[0][0] = 1;
  for (int i = 1; i < N; i++) {
    P[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      P[i][j] = (0ll + P[i - 1][j - 1] + P[i - 1][j]) % m;
    }
  }
}
void solve() {
  for (ll k = 0; k < 3; k++) {
    ll x = A[k], y = A[(k + 1) % 3];
    for (ll i = 0; i <= min(x, y); i++) {
      t[k] = (t[k] + (1ll * P[x][i] * P[y][i] % m) * F[i] % m) % m;
    }
  }
  cout << (1ll * t[0] * t[1] % m) * t[2] % m << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}