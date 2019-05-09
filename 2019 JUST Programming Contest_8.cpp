#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N];
int T;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> s;
    int f = 1;
    for (int j = 1; j < s[j]; j++) {
      if (s[j] - s[j - 1] != 1 && !(s[j - 1] == 'z' && s[j] == 'a')) {
        cout << "NO\n";
        f = 0;
        break;
      }
    }
    if (f) cout << "YES\n";
  }
  return 0;
}