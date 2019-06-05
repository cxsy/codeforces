#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string s;
void solve() {
  cin >> s;
  for (char c : s) {
    cnt[c - 'a']++;
  }
  vector<int> v;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2) {
      v.emplace_back(i);
    }
  }
  for (int i = 0; i < v.size() / 2; i++) {
    cnt[v[i]]++;
    cnt[v[v.size() - 1 - i]]--;
  }
  string sol = "";
  for (int i = 0; i < 26; i++) {
    sol += string(cnt[i] / 2, char('a' + i));
  }
  string re = sol;
  reverse(re.begin(), re.end());
  if (v.size() % 2) {
    sol += char('a' + v[v.size() / 2]);
  }
  cout << (sol + re) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}