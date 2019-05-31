#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 2e5 + 5;
const int m = 998244353;
ll A[N], B[N];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i] = A[i] * (i + 1) * (n - i);
  }
  sort(A, A + n);
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  sort(B, B + n, greater<int>());
  ll sol = 0;
  for (int i = 0; i < n; i++) {
    sol = (sol + (A[i] % m) * B[i] % m) % m;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}