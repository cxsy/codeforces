#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int A[N];
int n;
void build() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
}
int helper(int l, int r, int h) {
  if (l > r) return 0;
  int mh = 1e9 + 5, m;
  for (int i = l; i <= r; i++) {
    if (A[i] < mh) {
      mh = A[i];
      m = i;
    }
  }
  return min(r - l + 1, helper(l, m - 1, mh) + helper(m + 1, r, mh) + mh - h);
}
void solve() { cout << helper(0, n - 1, 0) << "\n"; }
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}