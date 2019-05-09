#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
string s;
string sta[N];
int n, top;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "pwd") {
      for (int j = 0; j < top; j++) {
        cout << "/" << sta[j];
      }
      cout << "/\n";
    } else {
      cin >> s;
      if (s[0] == '/') top = 0;
      int curs = -1, nexs;
      while (curs != s.size()) {
        nexs = s.find('/', curs + 1);
        if (nexs == string::npos) nexs = s.size();
        if (s.substr(curs + 1, nexs - curs - 1) == "..") {
          top--;
        } else if (nexs > curs + 1) {
          sta[top++] = s.substr(curs + 1, nexs - curs - 1);
        }
        curs = nexs;
      }
    }
  }
  return 0;
}