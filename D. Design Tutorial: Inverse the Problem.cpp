#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define exit(s) cout << (s) << "\n", exit(0);
#define ii pair<int, ll>
struct e {
  int from, to, w;
};
const int N = 2005;
int A[N][N], r[N];
int n;
bool vis[N];
bool comp(const e &a, const e &b) { return a.w < b.w; }
int find_set(int i) { return i == r[i] ? i : r[i] = find_set(r[i]); }
vector<e> v;
vector<vector<ii>> nei(N);
void build() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    r[i] = i;
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
}
void bfs(int i) {
  fill(vis, vis + n, false);
  queue<ii> que;
  que.push(ii{i, 0});
  vis[i] = true;
  while (!que.empty()) {
    ii h = que.front();
    que.pop();
    for (ii ne : nei[h.first]) {
      int j = ne.first;
      if (!vis[j]) {
        vis[j] = true;
        ll d = h.second + ne.second;
        if (A[i][j] != d) {
          exit("NO");
        }
        que.push(ii{j, d});
      }
    }
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    if (A[i][i]) exit("NO");
    for (int j = i + 1; j < n; j++) {
      if (!A[i][j] || A[i][j] != A[j][i]) exit("NO");
      v.emplace_back(e{i, j, A[i][j]});
    }
  }
  sort(v.begin(), v.end(), comp);
  for (e c : v) {
    int from = c.from, to = c.to, w = c.w;
    int a1 = find_set(from), a2 = find_set(to);
    if (a1 != a2) {
      r[a2] = a1;
      nei[from].emplace_back(ii{to, w});
      nei[to].emplace_back(ii{from, w});
    }
  }
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  exit("YES");
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}