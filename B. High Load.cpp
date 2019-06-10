#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k;
void solve() {
  cin >> n >> k;
  int l = (n - 1) / k, x = (n - 1) % k;
  int sol = 2 * l;
  if (x == 1) sol += 1;
  if (x >= 2) sol += 2;
  cout << sol << "\n";
  int cnt = 2;
  for (int i = 0; i < k; i++) {
    cout << 1 << " " << cnt << "\n";
    int t = i < x ? l : l - 1;
    for (int k = 0; k < t; k++) {
      cout << cnt << " " << cnt + 1 << "\n";
      cnt++;
    }
    cnt++;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}