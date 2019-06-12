#include <bits/stdc++.h>
using namespace std;
int n, q, t, x;
void solve() {
  cin >> n >> q;
  int p1 = 1, p2 = 2;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 2) {
      p1 += p1 % 2 == 1 ? 1 : -1;
      p2 += p2 % 2 == 1 ? 1 : -1;
    } else {
      cin >> x;
      p1 = (p1 - 1 + x + n) % n + 1;
      p2 = (p2 - 1 + x + n) % n + 1;
    }
  }
  vector<int> sol(n + 1);
  for (int i = 0; i < n / 2; i++) {
    sol[p1] = 2 * i + 1;
    p1 = (p1 - 1 + 2 + n) % n + 1;
    sol[p2] = 2 * i + 2;
    p2 = (p2 - 1 + 2 + n) % n + 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " \n"[i == n];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}