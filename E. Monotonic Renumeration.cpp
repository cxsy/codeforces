#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int m = 998244353;
int A[N];
int n;
map<int, int> last;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    last[A[i]] = i;
  }

  int i = 1;
  int64_t sol = 1;
  while (i <= n) {
    if (i > 1) sol = sol * 2 % m;
    int ne = last[A[i]];
    for (int j = i; j <= ne; j++) {
      ne = max(ne, last[A[j]]);
    }
    i = ne + 1;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}