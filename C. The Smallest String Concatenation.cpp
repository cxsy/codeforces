#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
string S[N];
int n;
bool comp(const string& a, const string& b) { return a + b < b + a; }
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  sort(S, S + n, comp);
  string sol = "";
  for (string s : S) {
    sol += s;
  }
  cout << sol << "\n";
}
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}