#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii pair<int, int>
int n;
string s;
vector<ii> vii;
bool comp(const ii &a, const ii &b) {
  return 1ll * a.first * b.second > 1ll * a.second * b.first;
}
void solve() {
  cin >> n;
  ll sol = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int scnt = 0;
    for (int c : s) {
      if (c == 's') scnt++;
      if (c == 'h') sol += scnt;
    }
    vii.emplace_back(ii{scnt, s.size() - scnt});
  }
  sort(vii.begin(), vii.end(), comp);
  int pres = 0;
  for (ii e : vii) {
    sol += 1ll * e.second * pres;
    pres += e.first;
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}