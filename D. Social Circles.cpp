#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int L[N], R[N];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }
  sort(L, L + n);
  sort(R, R + n);
  int64_t sol = 0;
  for (int i = 0; i < n; i++) {
    sol += max(L[i], R[i]) + 1;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}