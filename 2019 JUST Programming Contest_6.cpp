#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
int T;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> s;
    int count = 0, f = 1;
    for (int i = 0; i < s[i]; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') count++;
      if (count > 7) {
        cout << "NO\n";
        f = 0;
        break;
      }
    }
    if (f) cout << "YES\n";
  }
  return 0;
}