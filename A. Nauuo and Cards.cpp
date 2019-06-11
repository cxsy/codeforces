#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int A[N], B[N], P[N];
int n, sol;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    P[A[i]] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
    P[B[i]] = i;
  }
  if (P[1]) {
    int i;
    for (i = 2; i <= n && P[i] == P[i - 1] + 1; i++);
    if (P[i - 1] == n) {
      int j;
      for (j = i; j <= n && P[j] <= j - i; j++);
      if (j > n) {
        cout << n - i + 1 << "\n";
        exit(0);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    sol = max(sol, P[i] - i + 1 + n);
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}