#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int sol[N][N];
int n, k, d, cnt = 0;
void dfs(int t) {
  if (t == d) {
    cnt++;
    if (cnt == n) {
      for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
          sol[j][i] = sol[j][i] ? sol[j][i] : sol[j - 1][i];
          cout << sol[j][i] << " \n"[j == n - 1];
        }
      }
      exit(0);
    }
    return;
  }
  for (int i = 1; i <= k; i++) {
    sol[cnt][t] = i;
    dfs(t + 1);
  }
}
void solve() {
  cin >> n >> k >> d;
  dfs(0);
  cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}