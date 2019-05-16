#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define ii pair<ll, int>
#define INF INT64_MAX

const int N = int(1e5) + 5;
unordered_map<int, unordered_map<int, int>> edge;
uint8_t re[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, u, v, x, s, y;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> x;
    edge[v][u] = edge[u][v] = edge[u][v] ? min(edge[u][v], x) : x;
  }
  vector<ll> d(n + 1);
  d.assign(n + 1, INF);
  d[1] = 0;
  for (int i = 0; i < k; i++) {
    cin >> s >> y;
    d[s] = min(d[s], ll(y));
    re[s] = 1;
  }
  priority_queue<ii, vector<ii>, greater<ii>> q;
  for (int v = 1; v <= n; v++) {
    if (d[v] < INF) q.push({d[v], v});
  }
  while (!q.empty()) {
    int v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d[v] != d_v) continue;
    for (auto adj : edge[v]) {
      int to = adj.first;
      int len = adj.second;
      if (d[v] + len <= d[to]) {
        re[to] = 0;
        if (d[to] > d[v] + len) {
          d[to] = d[v] + len;
          q.push({d[to], to});
        }
      }
    }
  }
  int sol = 0;
  for (int v = 1; v <= n; v++) sol += re[v];
  cout << k - sol << "\n";
  return 0;
}