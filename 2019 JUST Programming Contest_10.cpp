#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
unordered_map<int, int> mm1, mm2;
int T, n, m, v;
int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d%d", &n, &m);
    int sol = 0;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        scanf("%d", &v);
        mm2[v]++;
        if (mm1[v]) {
          mm1[v]--;
          sol++;
        }
      }
      mm1 = mm2;
      mm2.clear();
    }
    cout << sol << "\n";
  }
  return 0;
}