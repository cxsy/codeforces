#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int64_t ans = 0, left = 0;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val / 2 >= left) {
      val -= 2 * left;
      ans += left + val / 3;
      left = val % 3;
    } else {
      ans += val / 2;
      left = left - val / 2 + val % 2;
    }
  }
  cout << ans << "\n";
  return 0;
}