#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, h, w;
int A[N][N], sm[N][N], bi[N][N];

bool is(int k) {
  fill(&sm[0][0], &sm[0][0] + N * N, 0);
  fill(&bi[0][0], &bi[0][0] + N * N, 0);
  for (int i = 1; i <= n; i++) {
    int ss = 0, bb = 0;
    for (int j = 1; j <= m; j++) {
      ss += A[i][j] < k;
      bb += A[i][j] > k;
      sm[i][j] += sm[i - 1][j] + ss;
      bi[i][j] += bi[i - 1][j] + bb;
    }
  }
  bool f = true;
  for (int i = 1; i <= n - h + 1 && f; i++) {
    for (int j = 1; j <= m - w + 1 && f; j++) {
      int ss = sm[i + h - 1][j + w - 1] + sm[i - 1][j - 1] -
               sm[i + h - 1][j - 1] - sm[i - 1][j + w - 1];
      int bb = bi[i + h - 1][j + w - 1] + bi[i - 1][j - 1] -
               bi[i + h - 1][j - 1] - bi[i - 1][j + w - 1];
      if (ss > bb) f = false;
    }
  }
  return f;
}
int main(int argc, char const *argv[]) {
  scanf("%d%d%d%d", &n, &m, &h, &w);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);
  int l = 1, h = n * m;
  while (l <= h) {
    int mid = (l + h) >> 1;
    if (is(mid)) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << l - 1 << "\n";
  return 0;
}