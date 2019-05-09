#include <bits/stdc++.h>
using namespace std;
int g[5][5];
char s[3];
char ans[5];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 5; i++) {
    cin >> s;
    int a = s[0] - 'A', b = s[2] - 'A';
    if (s[1] == '<')
      g[a][b] = 1;
    else
      g[b][a] = 1;
  }
  for (int k = 0; k < 5; k++)
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) g[i][j] |= (g[i][k] & g[k][j]);
  for (int i = 0; i < 5; i++) {
    if (g[i][i]) {
      cout << "impossible\n";
      exit(0);
    }
  }
  for (int i = 0; i < 5; i++) ans[i] = char(i + 'A');
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (g[ans[j] - 'A'][ans[i] - 'A']) {
        swap(ans[i], ans[j]);
      }
    }
  }
  for (int i = 0; i < 5; i++) cout << ans[i];
  cout << "\n";
  return 0;
}