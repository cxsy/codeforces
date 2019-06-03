#include <bits/stdc++.h>
using namespace std;
const int P = 1 << 17;
bool vis[1 << 20];
vector<int> sol;
int n, x;
void solve() {
  cin >> n >> x;
  if (n == 1) {
    cout << "YES\n" << x << "\n";
    exit(0);
  }
  if (n == 2 && x == 0) {
    cout << "NO\n";
    exit(0);
  }
  sol.resize(n + 1);
  int y = 0;
  for (int i = 1; i <= n - 3; i++) {
    y ^= i;
    sol[i] = i;
  }
  if (x == y) {
    sol[n - 2] = P;
    sol[n - 1] = P << 1;
    sol[n] = sol[n - 2] | sol[n - 1];
  } else {
    sol[n - 2] = 0;
    sol[n - 1] = P;
    sol[n] = P ^ x ^ y;
  }
  cout << "YES\n";
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