#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii pair<int, int>
#define mp make_pair
int maxw, maxh;
int w, h, n;
void helper(int d, priority_queue<ii>& q, set<int>& s, set<ii>& sd) {
  auto p = s.upper_bound(d);
  int up = *p, down = *(--p);
  s.insert(d);
  sd.insert(mp(up - down, down));
  q.push(mp(up - d, d));
  q.push(mp(d - down, down));
  while (sd.count(q.top())) q.pop();
}
void solve() {
  cin >> w >> h >> n;
  maxw = w, maxh = h;
  priority_queue<ii> hq, vq;
  set<int> hs({0, h}), vs({0, w});
  set<ii> hd, vd;
  hq.push(mp(0, h));
  vq.push(mp(0, w));
  char c;
  int d;
  for (int i = 0; i < n; i++) {
    cin >> c >> d;
    if (c == 'H') {
      helper(d, hq, hs, hd);
      maxh = hq.top().first;
    } else {
      helper(d, vq, vs, vd);
      maxw = vq.top().first;
    }
    cout << 1ll * maxh * maxw << "\n";
  }
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}