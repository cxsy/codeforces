#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define INF INT64_MAX

const int N = 1e5 + 1000;
const int M = 6e5 + 1000;
struct {
  int to, pre;
  ll w;
} E[M];
int tot = 0;
int la[N];
bool inq[N];
uint8_t re[N];
ll d[N];
deque<int> q;
void addEdge(int u, int v, int x) {
  E[++tot].to = v;
  E[tot].pre = la[u];
  E[tot].w = x;
  la[u] = tot;
};
int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n, m, k, u, v, x, s, y;
  // cin >> n >> m >> k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    // cin >> u >> v >> x;
    scanf("%d%d%d", &u, &v, &x);
    addEdge(u, v, x);
    addEdge(v, u, x);
  }
  fill(d, d + n + 1, INF);
  d[1] = 0;
  q.push_back(1);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &s, &y);
    d[s] = min(d[s], ll(y));
    if (!re[s]) q.push_back(s), inq[s] = true;
    re[s] = 1;
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    inq[v] = false;
    for (int ei = la[v]; ei; ei = E[ei].pre) {
      int to = E[ei].to, len = E[ei].w;
      if (d[to] >= d[v] + len) {
        re[to] = 0;
        if (d[to] > d[v] + len) {
          d[to] = d[v] + len;
          if (!inq[to]) {
            inq[to] = true;
            if (q.empty() || d[to] <= d[q.front()]) {
              q.push_front(to);
            } else {
              q.push_back(to);
            }
          }
        }
      }
    }
  }
  int sol = 0;
  for (int v = 1; v <= n; v++) sol += re[v];
  // cout << k - sol << "\n";
  printf("%d\n", k - sol);
  return 0;
}