#include <bits/stdc++.h>
using namespace std;
#define exit(s) cout << (s) << "\n", exit(0)
#define ii pair<int, int>
#define mp make_pair
const int N = 505;
char M[N][N];
bool vis[N][N], adj;
int n, m, r1, c1, r2, c2;
int di[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool in(int r, int c) { return 1 <= r && r <= n && 1 <= c && c <= m; }
void build() {
  cin >> n >> m;
  for (int r = 1; r <= n; r++)
    for (int c = 1; c <= m; c++) cin >> M[r][c];
  cin >> r1 >> c1 >> r2 >> c2;
  adj = (abs(r1 - r2) + abs(c1 - c2) == 1);
}
void solve() {
  queue<ii> q({mp(r1, c1)});
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    if (r == r2 && c == c2) {
      if ((r1 != r2 || c1 != c2) && M[r2][c2] == 'X') exit("YES");
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nr = r2 + di[d][0], nc = c2 + di[d][1];
        cnt += int(in(nr, nc) && M[nr][nc] == '.');
      }
      if (r1 == r2 && c1 == c2 && cnt >= 1) exit("YES");
      if ((r1 != r2 || c1 != c2) && cnt >= 1 && adj) exit("YES");
      if ((r1 != r2 || c1 != c2) && cnt >= 2 && !adj) exit("YES");
      exit("NO");
    }
    for (int d = 0; d < 4; d++) {
      int nr = r + di[d][0], nc = c + di[d][1];
      if (in(nr, nc) && (M[nr][nc] == '.' || (nr == r2 && nc == c2)) && !vis[nr][nc]) {
        vis[nr][nc] = true;
        q.push(mp(nr, nc));
      }
    }
  }
  exit("NO");
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}