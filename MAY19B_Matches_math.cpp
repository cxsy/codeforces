#include <bits/stdc++.h>
using namespace std;
#define LL int64_t
unordered_map<LL, unordered_map<LL, bool>> mm;
bool dfs(int n, int m) {
  if (n < m) swap(n, m);
  if (m == 0) return false;
  if (mm[n].count(m)) return mm[n][m];
  if (n / m >= 2) return mm[n][m] = (n / m >= 2 ? true : !dfs(n % m, m));
}
main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, N, M;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N >> M;
    mm.clear();
    cout << (dfs(N, M) ? "Ari" : "Rich") << "\n";
  }
  return 0;
}