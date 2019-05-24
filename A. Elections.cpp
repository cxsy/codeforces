#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii pair<int, int>
#define mp make_pair
const int N = 3005;
vector<ii> pp[N], ps;
int n, m, vo[N], pi[N], ne[N];
int getNext(int i) { return i == ne[i] ? i : ne[i] = getNext(ne[i]); }
void solve() {
  cin >> n >> m;
  int p, c;
  ll sol = 1e15;
  for (int i = 1; i <= n; i++) {
    cin >> p >> c;
    pp[p].emplace_back(mp(c, i));
    ps.emplace_back(mp(c, i));
    vo[i] = p;
    ne[i] = i;
  }
  sort(ps.begin(), ps.end());
  for (int i = 2; i <= m; i++) {
    sort(pp[i].begin(), pp[i].end());
    pi[i] = 0;
  }
  ll cb = 0;
  int p1 = pp[1].size();
  int t = p1;
  for (int x = n; x >= max(1, p1); x--) {
    for (int i = 2; i <= m; i++) {
      while (pp[i].size() - pi[i] >= x) {
        cb += pp[i][pi[i]].first;
        t++;
        vo[pp[i][pi[i]].second] = 1;
        pi[i]++;
      }
    }
    int diff = x - t;
    ll ce = 0;
    for (int k = 0; k < n && diff > 0; k++) {
      if (vo[ps[k].second] == 1) continue;
      diff--;
      ce += ps[k].first;
    }
    sol = min(sol, cb + ce);
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}