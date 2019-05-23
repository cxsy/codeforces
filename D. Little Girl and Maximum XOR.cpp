#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll l, r;
void solve() {
  cin >> l >> r;
  bitset<63> b1(l);
  bitset<63> b2(r);
  int i = 62;
  while (i >= 0 && b1[i] == b2[i]) i--;
  cout << (1ll << (i + 1)) - 1 << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}