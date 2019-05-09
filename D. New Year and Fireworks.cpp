#include <bits/stdc++.h>
using namespace std;
const int M = 350, N = 32, T = 6;
const int di[8]{-M, -M + 1, 1, M + 1, M, M - 1, -1, -M - 1};
bool dp[M * M][T][8], v[M * M];
int t[N];
int ans = 0;

void helper(int p, int e, int d) {
  if (t[e] && !dp[p][t[e]][d]) {
    dp[p][t[e]][d] = 1;
    for (int i = 0; i < t[e]; i++) p += di[d], ans += v[p] ? 0 : v[p] = true;
    helper(p, e + 1, (d + 7) % 8);
    helper(p, e + 1, (d + 1) % 8);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  helper(M * M / 2, 0, 0);
  cout << ans << "\n";
  return 0;
}