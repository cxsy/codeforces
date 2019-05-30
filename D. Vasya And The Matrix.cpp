#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], b[N];
int n, m;
void solve() {
  cin >> n >> m;
  int ro = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ro ^= a[i];
  }
  int co = 0;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    co ^= b[i];
  }
  if (ro != co) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i != n - 1 && j != m - 1) {
        cout << "0 ";
      }
      if (i != n - 1 && j == m - 1) {
        cout << a[i] << "\n";
      }
      if (i == n - 1 && j != m - 1) {
        cout << b[j] << " ";
      }
      if (i == n - 1 && j == m - 1) {
        cout << (co ^ a[n - 1] ^ b[m - 1]) << "\n";
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}