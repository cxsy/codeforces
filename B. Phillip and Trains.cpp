#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
const int N = 105;
bool vis[3][N];
int t, n, k;
string s[3];
string su = "...";
void solve() {
  cin >> t;
  while (t) {
    t--;
    fill(&vis[0][0], &vis[0][0] + 3 * N, false);
    cin >> n >> k;
    int sr, sc = 0;
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
      if (s[i][0] == 's') sr = i;
      s[i] += su;
    }
    queue<ii> que;
    que.push(ii{sr, sc});
    bool f = true;
    while (!que.empty()) {
      ii h = que.front();
      que.pop();
      int r = h.first, c = h.second;
      if (c >= n) {
        cout << "YES\n";
        f = false;
        break;
      };
      if (s[r][c + 1] == '.') {
        if (r - 1 >= 0 && s[r - 1].substr(c + 1, 3) == "..." && !vis[r - 1][c + 3]) {
          que.push(ii{r - 1, c + 3});
          vis[r - 1][c + 3] = true;
        }
        if (s[r].substr(c + 1, 3) == "..." && !vis[r][c + 3]) {
          que.push(ii{r, c + 3});
          vis[r][c + 3] = true;
        }
        if (r + 1 < 3 && s[r + 1].substr(c + 1, 3) == "..." && !vis[r + 1][c + 3]) {
          que.push(ii{r + 1, c + 3});
          vis[r + 1][c + 3] = true;
        }
      }
    }
    if (f) cout << "NO\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}