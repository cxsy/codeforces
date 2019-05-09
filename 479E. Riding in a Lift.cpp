#include <iostream>
using namespace std;

const int NMAX = 5005;
const int mod = 1000000009;
int dp[NMAX];

int main(int argc, char const *argv[]) {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (a > b) {
    a = n + 1 - a;
    b = n + 1 - b;
  }
  if (abs(a - b) == 1) {
    cout << 0 << "\n";
    return;
  }
  dp[a] = 1;
  for (int i = 0; i < k; i++) {
    int tmp[NMAX];
    for (int to = 1; to <= b - 1; to++) {
      for (int from = 1; from <= b - 1; from++) {
        if (abs(from - to) >= abs(from - b)) {
          continue;
        }
        tmp[to] = (tmp[to] + tmp[from]) % mod;
      }
    }
    copy(begin(tmp), end(tmp), begin(dp));
  }
  int ans = 0;
  for (int f = 1; f < b; f++) {
    ans += dp[f];
  }

  return 0;
}
