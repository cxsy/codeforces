#include <bits/stdc++.h>
using namespace std;
const int K = 1e5 + 5;
int r[K];
int n, k;
void solve() {
  cin >> n >> k;
  int a, gcd;
  for (int i = 0; i < n; i++) {
    cin >> a;
    a %= k;
    if (a == 0) a = k;
    gcd = i == 0 ? a : __gcd(gcd, a);
  }
  int c = 0, cnt = 0;
  while (!r[c]) {
    r[c] = 1;
    cnt++;
    c = (c + gcd) % k;
  }
  cout << cnt << "\n";
  for (int i = 0; i < k && cnt; i++) {
    if (r[i]) {
      cout << i << " \n"[cnt == 1];
      cnt--;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}