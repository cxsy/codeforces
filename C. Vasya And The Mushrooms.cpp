#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 3e5 + 5;
ll A[2][N];
ll s12[2][N], s21[2][N], s11[2][N];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = n - 1; j >= 0; j--) {
      s12[i][j] = s12[i][j + 1] + j * A[i][j];
      s21[i][j] = s21[i][j + 1] + (n - 1 - j) * A[i][j];
      s11[i][j] = s11[i][j + 1] + A[i][j];
    }
  }
  ll sol = 0, pre = 0;
  for (int i = 0; i <= n; i++) {
    int t = i % 2;
    ll a = i == 0 ? 0 : s12[t][i - 1];
    ll b = i == 0 ? 0 : s11[t][i - 1];
    ll c = s21[1 ^ t][i];
    ll d = s11[1 ^ t][i];
    pre += (2 * i - 2) * A[1 ^ t][i - 1];
    pre += i > 1 ? (2 * i - 3) * A[1 ^ t][i - 2] : 0;
    ll le = a + i * b + c + (n + i) * d;
    sol = max(sol, pre + le);
  }
  cout << sol << '\n';
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}