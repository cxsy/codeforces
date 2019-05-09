
 #include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N], cs[N], p[26];
int T, n, m;
int cc[30];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    int sol = 0;
    fill(cc, cc + 26, INT32_MAX);
    cin >> n >> m;
    cin >> s >> cs;
    for (int j = 0; j < n; j++)
      cc[s[j] - 'a'] = min(cc[s[j] - 'a'], cs[j] - '0');
    cin >> p;
    bool f = true;
    for (int j = 0; j < m; j++) {
      if (cc[p[j] - 'a'] == INT32_MAX) {
        cout << "-1\n";
        f = false;
        break;
      }
      sol += cc[p[j] - 'a'];
    }
    if (f) cout << sol << "\n";
  }
  return 0;
}