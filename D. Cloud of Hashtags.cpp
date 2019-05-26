#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
string A[N];
int p[N];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    p[i] = A[i].size();
  }
  for (int i = n - 2; i >= 0; i--) {
    bool f = true;
    for (int j = 0; j < min(p[i], p[i + 1]); j++) {
      if (A[i][j] != A[i + 1][j]) {
        if (A[i][j] > A[i + 1][j]) p[i] = j;
        f = false;
        break;
      }
    }
    if (f) p[i] = min(p[i], p[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    cout << A[i].substr(0, p[i]) << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}