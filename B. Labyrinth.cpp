#include <bits/stdc++.h>
using namespace std;
struct state {
  int i, j, l;
};
const int N = 2005;
const int INF = 1e7;
const int di[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char G[N][N];
int le[N][N];
int n, m, r, c, x, y;
char ch;
void build() {
  cin >> n >> m >> r >> c >> x >> y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> G[i][j];
    }
  }
}
void solve() {
  deque<state> deq({{r, c, 0}});
  fill(&le[0][0], &le[0][0] + N * N, INF);
  le[r][c] = 0;
  while (!deq.empty()) {
    state f = deq.front();
    deq.pop_front();
    int i = f.i, j = f.j, l = f.l;
    for (int d = 0; d < 4; d++) {
      int ii = i + di[d][0], jj = j + di[d][1], ll = l + int(d == 3);
      if (1 <= ii && ii <= n && 1 <= jj && jj <= m && G[ii][jj] == '.' &&
          le[ii][jj] > ll) {
        le[ii][jj] = ll;
        if (d == 3) {
          deq.push_back({ii, jj, ll});
        } else {
          deq.push_front({ii, jj, ll});
        }
      }
    }
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (le[i][j] < INF) {
        int yy = le[i][j] + j - c;
        if (le[i][j] <= x && 0 <= yy && yy <= y) {
          sol++;
        }
      }
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}