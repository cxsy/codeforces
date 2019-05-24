#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int n, k;
ll INF = 1e14 + 5;
map<ll, int> mm;
set<ll> pp;
void solve() {
  cin >> n >> k;
  ll val, sum = 0, sol = 0;
  for (ll p = 1; abs(p) <= INF; p *= k) {
    if(pp.count(p)) break;
    pp.insert(p);
  }
  mm[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> val;
    sum += val;
    for (ll p : pp) {
      sol += mm[sum - p];  
    }
    mm[sum]++;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}