#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 4005;
int n;
ll v[N], d[N], p[N], ne[N];
int getNext(int i) { return i == ne[i] ? i : ne[i] = getNext(ne[i]); }
void build() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> d[i] >> p[i];
    ne[i] = i;
  }
  ne[n + 1] = n + 1;
}
void solve() {
  vector<int> sol;
  int st = 1;
  while (true) {
    bool f = true;
    int r;
    ll dd = 0;
    for (int i = getNext(1); i <= n; i = getNext(i)) {
      if (f) {
        f = false;
        r = v[i];
        sol.emplace_back(i);
        ne[i] = i + 1;
      } else {
        p[i] -= (max(0, r--) + dd);
        if (p[i] < 0) {
          dd += d[i];
          ne[i] = i + 1;
        }
      }
      i++;
    }
    if (f) break;
  }
  cout << sol.size() << "\n";
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i] << " \n"[i == sol.size() - 1];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}