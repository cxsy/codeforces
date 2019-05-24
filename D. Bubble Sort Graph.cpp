#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int A[N], n;
void solve() {
  cin >> n;
  int val, len = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    auto it = upper_bound(A, A + len, val);
    if (it - A == len) len++;
    *it = val;
  }
  cout << len << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}