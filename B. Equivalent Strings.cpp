#include <bits/stdc++.h>
using namespace std;
string s1, s2;
string smallest(string s) {
  if (s.size() % 2) return s;
  int subl = s.size() / 2;
  string s1 = smallest(s.substr(0, subl));
  string s2 = smallest(s.substr(subl));
  return s1 < s2 ? s1 + s2 : s2 + s1;
}

void solve() {
  cin >> s1 >> s2;
  s1 = smallest(s1);
  s2 = smallest(s2);
  cout << (s1 == s2 ? "YES" : "NO") << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}