#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v{1, 6, 8, 9};
int cnt[10];
string p[7];
int get(string x, int p) {
  int ret = 0;
  for (int i = x.size() - 1; i >= 0; i--) {
    ret = (ret + p * (x[i] - '0')) % 7;
    p = p * 10 % 7;
  }
  return ret;
}
void solve() {
  cin >> s;
  do {
    string t = "";
    for (int c : v) t += char('0' + c);
    p[get(t, 1)] = t;
  } while (next_permutation(v.begin(), v.end()));
  cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
  for (char c : s) {
    cnt[c - '0']++;
  }
  string sol = "";
  for (int i = 1; i <= 9; i++) sol += string(cnt[i], char('0' + i));
  int m = get(sol, 4);
  sol += p[(7 - m) % 7] + string(cnt[0], '0');
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}