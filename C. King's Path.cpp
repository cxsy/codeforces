#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define state tuple<int, int, int>
const int INF = 1e9 + 5;
const int di[8][2]{{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                   {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
map<int, vector<ii>> mv;
map<int, set<ii>> ms;
set<ii> vis;
int x0, y0, x1, y1, n, r, a, b;
bool is(int x, int y) {
  if (!ms.count(x)) return false;
  //   cout << x << " " << y << "*\n";
  auto it = ms[x].upper_bound(ii{y, INF});
  if (it == ms[x].begin()) return false;
  return (--it)->second >= y;
}
void solve() {
  cin >> x0 >> y0 >> x1 >> y1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r >> a >> b;
    mv[r].emplace_back(ii{a, b});
  }
  for (auto e : mv) {
    int rr = e.first;
    vector<ii> v = e.second;
    sort(v.begin(), v.end());
    v.emplace_back(ii{INF, INF});
    int l = -1, r = -1;
    for (ii p : v) {
      if (p.second <= r) continue;
      if (p.first > r + 1) {
        if (r > 0) ms[rr].insert(ii{l, r});
        l = p.first;
      }
      r = p.second;
    }
    // cout << rr << "*\n";
    // for (ii k : ms[rr]) {
    //   cout << k.first << "->" << k.second << "**\n";
    // }
  }
  queue<state> que;
  que.push(state{x0, y0, 0});
  while (!que.empty()) {
    int x, y, p;
    tie(x, y, p) = que.front();
    que.pop();
    if (x == x1 && y == y1) {
      cout << p << "\n";
      exit(0);
    }
    for (int d = 0; d < 8; d++) {
      int xx = x + di[d][0], yy = y + di[d][1];
      //   cout << xx << " " << yy << " " << p << "\n";
      if (is(xx, yy) && !vis.count(ii{xx, yy})) {
        que.push(state{xx, yy, p + 1});
        vis.insert(ii{xx, yy});
      }
    }
  }
  cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}