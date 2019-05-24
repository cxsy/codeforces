#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int H[N], l[N], r[N];
int n;
void build() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> H[i];
  }
}
void solve() {
  int lmin = N, rmin = N;
  for (int i = 0; i <= n; i++) {
    lmin = min(lmin, H[i] - i);
    l[i] = lmin + i;
    rmin = min(rmin, H[n + 1 - i] - i);
    r[n + 1 - i] = rmin + i;
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    sol = max(sol, min(l[i], r[i]));
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}