#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5 + 5;
int A[3][26];
string s[3];
void solve() {
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    for (char c : s[i]) {
      A[i][c - 'a']++;
    }
  }
  int sol = 0, max1 = INF;
  for (int i = 0; i < 26; i++) {
    if (A[1][i] == 0) continue;
    max1 = min(max1, A[0][i] / A[1][i]);
  }
  int v1 = 0, v2 = 0;
  for (int k = 0; k <= max1; k++) {
    int n2 = INF;
    for (int i = 0; i < 26; i++) {
      if (A[2][i] == 0) continue;
      n2 = min(n2, (A[0][i] - A[1][i] * k) / A[2][i]);
    }
    if (k + n2 > sol) {
      sol = k + n2;
      v1 = k;
      v2 = n2;
    }
  }
  string ss = "";
  for (int i = 0; i < v1; i++) {
    ss += s[1];
  }
  for (int i = 0; i < v2; i++) {
    ss += s[2];
  }
  for (int i = 0; i < 26; i++) {
    A[0][i] -= (A[1][i] * v1 + A[2][i] * v2);
    for (int j = 0; j < A[0][i]; j++) {
      ss += char('a' + i);
    }
  }
  cout << ss << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}