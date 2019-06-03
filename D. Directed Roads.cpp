#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int m = 1e9 + 7;
const int N = 2e5 + 5;
int A[N], V[N];
int n, ic = 0;
ll sol = 1;
ll binpow(int a, int b) {
  ll ac = a % m, ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * ac % m;
    }
    ac = ac * ac % m;
    b >>= 1;
  }
  return ret;
}
void dfs(int i, int c) {
  V[i] = -c;
  if (V[A[i]] < 0) {
    int cnt = V[A[i]] - V[i] + 1;
    sol = sol * ((binpow(2, cnt) + m - 2) % m) % m;
    ic += cnt;
  } else if (V[A[i]] == 0) {
    dfs(A[i], c + 1);
  }
  V[i] = -V[i];
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    if (V[i]) continue;
    dfs(i, 1);
  }
  sol = sol * binpow(2, n - ic) % m;
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}