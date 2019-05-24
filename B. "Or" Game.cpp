#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 2e5 + 5;
int A[N];
int cnt[30];
int n, k, x, m;
void build() {
  cin >> n >> k >> x;
  m = int(pow(x, k));
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    for (int b = 0; b < 30; b++) {
      cnt[b] += (A[i] & (1 << b)) ? 1 : 0;
    }
  }
}
void solve() {
  ll sol = 0;
  for (int i = 0; i < n; i++) {
    int temp[30]{};
    int val = 0;
    ll am = 1ll * A[i] * m;
    for (int b = 0; b < 30; b++) {
      temp[b] = cnt[b] - ((A[i] & (1 << b)) ? 1 : 0);
      if (temp[b] > 0) {
        am |= (1 << b);
      }
    }
    sol = max(sol, am);
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}