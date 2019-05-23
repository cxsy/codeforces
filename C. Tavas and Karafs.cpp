#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int A, B, n;
bool get(int l, int r, ll mt) {
  return 1ll * A * (r - l + 1) + 1ll * B * (r + l - 2) * (r - l + 1) / 2 <= mt;
}
void helper(int l, int t, int m) {
  ll mt = 1ll * t * m;
  int L = l, R = (t - A) / B + 1;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (get(l, mid, mt)) {
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  L--;
  cout << (L < l ? -1 : L) << "\n";
}
void solve() {
  cin >> A >> B >> n;
  int l, t, m;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    helper(l, t, m);
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}