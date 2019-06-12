#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  cin >> n;
  int64_t sol = 0;
  for (int i = 2; i <= n; i++) {
    sol += int64_t(2) * (n / i) * (n / i + 1) - 4;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0; 
}