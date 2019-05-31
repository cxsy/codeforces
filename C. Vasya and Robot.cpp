#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int di[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char ops[N];
int opi[N];
int n, x, y, F[N][2], B[N][2];
bool test(int m) {
  for (int i = 0; i + m <= n; i++) {
    int diff = abs(F[i][0] - B[i + m + 1][0]) + abs(F[i][1] - B[i + m + 1][1]);
    if (diff <= m && diff % 2 == m % 2) {
      return true;
    }
  }
  return false;
}
void solve() {
  cin >> n >> ops >> x >> y;
  for (int i = 1; i <= n; i++) {
    if (ops[i - 1] == 'U') opi[i] = 0;
    if (ops[i - 1] == 'R') opi[i] = 1;
    if (ops[i - 1] == 'D') opi[i] = 2;
    if (ops[i - 1] == 'L') opi[i] = 3;
  }
  for (int i = 1; i <= n; i++) {
    F[i][0] = F[i - 1][0] + di[opi[i]][0];
    F[i][1] = F[i - 1][1] + di[opi[i]][1];
  }
  B[n + 1][0] = x, B[n + 1][1] = y;
  for (int i = n; i >= 1; i--) {
    B[i][0] = B[i + 1][0] - di[opi[i]][0];
    B[i][1] = B[i + 1][1] - di[opi[i]][1];
  }
  int l = 0, h = n;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (test(mid)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  h++;
  cout << (h > n ? -1 : h) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}