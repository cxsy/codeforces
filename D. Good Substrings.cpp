#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
string s;
const int N = 1505;
char J[26];
int k, p = 31;
ll m = (1ll << 60) - 1, pp[N], al[26];
unordered_set<ll> ss;
void build() {
  cin >> s >> J >> k;
  pp[0] = 1;
  for (int i = 0; i < 26; i++) al[i] = i + 1;
  for (int i = 1; i < N; i++) {
    pp[i] = (1ll * pp[i - 1] * p) % m;
  }
}
void solve() {
  int len = s.size(), sol = 0;
  for (int i = 0; i < len; i++) {
    string sb;
    int bcnt = 0;
    ll h = 0;
    for (int j = i; j < len; j++) {
      sb += s[j];
      h = (h + pp[j - i] * al[s[j] - 'a']) % m;
      bcnt += (J[s[j] - 'a'] == '0');
      if (bcnt > k) break;
      if (!ss.count(h)) sol++;
      ss.insert(h);
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}