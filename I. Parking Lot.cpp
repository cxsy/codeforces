#include <bits/stdc++.h>
using namespace std;
int64_t t4[31]{1};
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i < 31; i++) {
    t4[i] = t4[i - 1] << 2;
  }
  int64_t ans = 2 * 4 * 3 * t4[n - 3];
  if (n >= 4) ans += (n - 3) * (4 * 3 * 3 * t4[n - 4]);
  cout << ans << "\n";
  return 0;
}