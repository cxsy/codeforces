#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii pair<ll, int>
const int N = 1e5 + 5;
int n, k;
ll INF = 1e14 + 5;
map<ll, int> mm;
set<ll> pp;
ii A[N];
void solve() {
  cin >> n >> k;
  ll val, sum = 0, sol = 0;
  for (ll p = 1; abs(p) <= INF; p *= k) {
    if (pp.count(p)) break;
    pp.insert(p);
  }
  for (int i = 1; i <= n; i++) {
    cin >> val;
    A[i] = {A[i - 1].first + val, i};
  }
  ++n;
  A[n] = {4 * INF, n};
  sort(A, A + n);
  for (ll p : pp) {
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
      ii t = A[i];
      t.first += p;
      while (A[left] < t) ++left;
      while (A[right].first <= t.first) ++right;
      sol += right - left;
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}