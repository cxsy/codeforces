#include <bits/stdc++.h>
using namespace std;
const int N = 105;
double p[N];
int n;
void solve() {
  cin >> n;
  double maxx = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  double p1 = 1.0, p2 = 0.0, sol = 0.0;
  for (int i = n - 1; i >= 0; i--) {
    p2 = p2 * (1 - p[i]) + p1 * p[i];
    p1 = p1 * (1.0 - p[i]);
    sol = max(sol, p2);
  }
  cout.precision(10);
  cout << fixed << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}