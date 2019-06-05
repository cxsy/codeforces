#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int m[N], t[N];
int n;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  for (int i = n; i >= 1; i--) {
    t[i] = max(t[i + 1] - 1, m[i] + 1);
  }
  int64_t sol = 0;
  for (int i = 1; i <= n; i++) {
    t[i] = max(t[i], t[i - 1]);
    sol += t[i];
  }
  for (int i = 1; i <= n; i++) sol -= m[i] + 1;
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}