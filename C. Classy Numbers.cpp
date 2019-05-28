#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int table[20][3];
int nt[3]{1, 9, 81};
ll get(ll x) {
  string s = to_string(x);
  int len = s.size();
  if (len == 1) {
    return x - 1;
  }
  ll ret = 0;
  for (int i = 1; i < len; i++) {
    for (int j = 0; j <= min(i - 1, 2); j++) {
      ret += 1ll * 9 * nt[j] * table[i - 1][j];
    }
  }
  for (int i = 0, cnt = 0; i < len; i++) {
    if (s[i] > '0') {
      if (cnt < 3) {
        cnt++;
        for (int j = 0; j <= min(len - i - 1, 3 - cnt); j++) {
          ret += 1ll * (s[i] - '1') * nt[j] * table[len - i - 1][j];
        }
        if (i > 0) {
          for (int j = 0; j <= min(len - i - 1, 4 - cnt); j++) {
            ret += 1ll * nt[j] * table[len - i - 1][j];
          }
        }
      } else {
        ret++;
        break;
      }
    }
  }
  return ret;
}
ll T, L, R;
void solve() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j <= min(i, 2); j++) {
      table[i][j] = 1;
      for (int k = i - j + 1; k <= i; k++) {
        table[i][j] *= k;
      }
      for (int k = 1; k <= j; k++) {
        table[i][j] /= k;
      }
    }
  }
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> L >> R;
    cout << (get(R + 1) - get(L)) << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}