#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll l, r;
void solve() {
  cin >> l >> r;
  int i = 0;
  for (int i = 62; i >=0; i--) {
    if (((1ll << i) & l) == ((1ll << i) & r)) continue;
    cout << (1ll << (i + 1)) - 1 << "\n";
    exit(0);
  }
  cout << "0\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}