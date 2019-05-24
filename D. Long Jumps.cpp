#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e5 + 5;
int A[N];
ll n, l, x, y;
unordered_set<ll> ss;
void solve() {
  cin >> n >> l >> x >> y;
  bool fx = false, fy = false, fxpy = false, fxmy = false;
  int ep, em1, em2;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    fx |= ss.count(A[i] - x);
    fy |= ss.count(A[i] - y);
    if (ss.count(A[i] - x - y)) {
      fxpy |= true;
      ep = A[i];
    }
    if (ss.count(A[i] - (y - x))) {
      if (!fxmy) em1 = A[i];
      em2 = A[i];
      fxmy |= true;
    }
    ss.insert(A[i]);
  }
  if (fx && fy) cout << "0\n", exit(0);
  if (fx || fy) cout << "1\n" << (!fx ? x : y) << "\n", exit(0);
  if (fxpy) cout << "1\n" << ep - x << "\n", exit(0);
  if (fxmy && em1 + x <= l) cout << "1\n" << em1 + x << "\n", exit(0);
  if (fxmy && em2 - y >= 0) cout << "1\n" << em2 - y << "\n", exit(0);
  cout << "2\n" << x << " " << y << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}