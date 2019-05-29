#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
string s;
int T, cnt[26];
string get(ii e) {
  string ret = "";
  for (int i = e.first + 1; i < e.second; i += 2) {
    ret += string(cnt[i], char('a' + i));
  }
  for (int i = e.first; i < e.second; i += 2) {
    ret += string(cnt[i], char('a' + i));
  }
  return ret;
}
void solve() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> s;
    fill(cnt, cnt + 26, 0);
    for (char c : s) {
      cnt[c - 'a']++;
    }
    vector<ii> v;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0) continue;
      int st = i;
      while (i + 1 < 26 && cnt[i + 1]) {
        i++;
      }
      v.emplace_back(ii{st, i + 1});
    }
    if (v.size() == 1 &&
        (v[0].second - v[0].first == 2 || v[0].second - v[0].first == 3)) {
      cout << "No answer\n";
    } else {
      string f = "", b = "", sol = "";
      for (int i = 0; i < v.size(); i++) {
        ii e = v[i];
        int l = e.second - e.first;
        if (l >= 4) {
          sol += get(e);
        } else if (l == 2 || l == 3) {
          sol += string(cnt[e.first], char('a' + e.first));
          if (i == 0) b += string(cnt[e.first + 1], char('a' + e.first + 1));
          if (i > 0) f += string(cnt[e.first + 1], char('a' + e.first + 1));
          if (l == 3) sol += string(cnt[e.first + 2], char('a' + e.first + 2));
        } else {
          sol += string(cnt[e.first], char('a' + e.first));
        }
      }
      cout << (f + sol + b) << "\n";
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}