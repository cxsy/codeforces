#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define ti tuple<int, int, int>
map<int, int> mm;
int n;
void solve() {
  cin >> n;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    mm[v]++;
  }
  priority_queue<ii> pq;
  for (auto e : mm) {
    pq.push(ii{e.second, e.first});
  }
  int sol = 0;
  vector<ti> out;
  while (pq.size() >= 3) {
    ii h1 = pq.top();
    pq.pop();
    ii h2 = pq.top();
    pq.pop();
    ii h3 = pq.top();
    pq.pop();
    sol += 1;
    h1.first -= 1;
    h2.first -= 1;
    h3.first -= 1;
    if (h1.first) {
      pq.push(ii{h1.first, h1.second});
    }
    if (h2.first) {
      pq.push(ii{h2.first, h2.second});
    }
    if (h3.first) {
      pq.push(ii{h3.first, h3.second});
    }
    int s[3]{h1.second, h2.second, h3.second};
    sort(s, s + 3, greater<int>());
    out.emplace_back(ti{s[0], s[1], s[2]});
  }
  cout << sol << "\n";
  for (int i = 0; i < sol; i++) {
    cout << get<0>(out[i]) << " " << get<1>(out[i]) << " " << get<2>(out[i])
         << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}