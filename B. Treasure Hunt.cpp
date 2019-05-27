#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<char, int> mm;
string sol[3]{"Kuro", "Shiro", "Katie"};
void solve() {
  cin >> n;
  int maxx = 0, cnt = 0, w = 0;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    for (int i = 0; s[i]; i++) {
      mm[s[i]]++;
    }
    int t = 0;
    for (auto e : mm) {
      t = max(t, e.second);
    }
    int len = s.size();
    t += n;
    if (t > len) {
      if (mm.size() >= 2) {
        t = len;
      } else {
        t = t == len + 1 ? len - 1 : len;
      }
    }
    if (t > maxx) {
      maxx = t;
      cnt = 1;
      w = i;
    } else if (t == maxx) {
      cnt++;
    }
    mm.clear();
  }
  if (cnt == 1) {
    cout << sol[w];
  } else {
    cout << "Draw\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}