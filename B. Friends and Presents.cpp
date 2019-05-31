#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int cnt1, cnt2, x, y;
void solve() {
  cin >> cnt1 >> cnt2 >> x >> y;
  ll l = 1, r = 1e18, xy = x * y, cnt3 = cnt1 + cnt2;;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (mid - mid / xy >= cnt3 && mid - mid / x >= cnt1 && mid - mid / y >= cnt2) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << r + 1 << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}