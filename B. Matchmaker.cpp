#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int mm[N][N], ma[N], ne[N];
int n, m;
void solve() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    mm[y][x]++;
    ma[y]++;
  }
  int tot = 0, b = 0;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (mm[y][x]) {
      mm[y][x]--;
      ma[y]--;
      tot++;
      b++;
    } else {
      ne[y]++;
    }
  }
  for (int i = 1; i <= 1000; i++) {
    tot += min(ma[i], ne[i]);
  }
  cout << tot << " " << b << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}