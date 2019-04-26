#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  vector<int> p(s.length());
  vector<int> rec(s.length());
  int l = 0;
  for (int i = 1; i < s.length(); i++) {
    while (s[i] != s[l] && l > 0) {
      l = p[l - 1];
    }
    if (s[i] == s[l]) {
      l++;
    }
    rec[l]++;
    p[i] = l;
  }
  while (l > 0) {
    if (rec[l] >= 2) {
      cout << s.substr(0, l) << "\n";
      return 0;
    }
    l = p[l - 1];
    rec[l]++;
  }
  cout << "Just a legend"
       << "\n";
  return 0;
}
