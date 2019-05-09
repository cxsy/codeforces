#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int di[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool g[N][N], v[N][N];
unordered_set<int> rows, cols;
int n, m;
void dfs(int r, int c) {
  rows.insert(r);
  cols.insert(c);
  if (rows.size() == n && cols.size() == m) {
    puts("YES");
    exit(0);
  }
  for (int d = 0; d < 4; d++) {
    int rr = (r + di[d][0] + n) % n, cc = (c + di[d][1] + m) % m;
    if (!v[rr][cc] && g[rr][cc]) {
      v[rr][cc] = true;
      dfs(rr, cc);
    }
  }
}
int main(int argc, char const *argv[]) {
  double t, p;
  scanf("%d%d%lf", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) scanf("%lf", &p), g[i][j] = p >= t;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] && !v[i][j]) {
        v[i][j] = true;
        rows.clear();
        cols.clear();
        dfs(i, j);
      }
    }
  }
  puts("NO");
  return 0;
}