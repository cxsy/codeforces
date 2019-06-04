#include <bits/stdc++.h>
using namespace std;
string s;
bool same(string t) {
  for (int i = 1; i < t.size(); i++) {
    if (t[i] != t[i - 1]) return false;
  }
  return true;
}
bool isp(string t) {
  int l = 0, r = t.size() - 1;
  while (l < r && t[l] == t[r]) {
    l++;
    r--;
  }
  return l >= r;
}
void solve() {
  cin >> s;
  if (same(s.substr(0, s.size() / 2))) {
    cout << "Impossible\n";
    exit(0);
  }
  int len = s.size();
  while (len % 2 == 0) {
    if (!isp(s.substr(0, len / 2))) {
      cout << 1 << "\n";
      exit(0);
    }
    len /= 2;
  }
  cout << 2 << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}