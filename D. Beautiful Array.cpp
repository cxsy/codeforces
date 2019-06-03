#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 3e5 + 5;
int n, x;
ll dp[3], t[3], sol = 0;
void solve() {
  cin >> n >> x;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    t[0] = max(ll(0), dp[0] + v);
    t[1] = max(ll(0), max(dp[0], dp[1]) + 1ll * x * v);
    t[2] = max(ll(0), max(dp[1], dp[2]) + v);
    copy(t, t + 3, dp);
    sol = max(sol, *max_element(dp, dp + 3));
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}