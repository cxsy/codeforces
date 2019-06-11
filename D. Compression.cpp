#include <bits/stdc++.h>
using namespace std;
const int N = 5205;
int A[N][N];
int n;
void solve() {
  cin >> n;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 4; j++) {
      cin >> c;
      int num;
      if (c >= 'A' && c <= 'F') {
        num = c - 'A' + 10;
      } else {
        num = c - '0';
      }
      for (int k = 0; k < 4; k++) {
        A[i][4 * j + k] = (num >> (3 - k)) & 1;
      }
    }
  }
  int sol = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 1;
      while (j + 1 < n && A[i][j] == A[i][j + 1]) {
        j++;
        cnt++;
      }
      sol = __gcd(sol, cnt);
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      int cnt = 1;
      while (i + 1 < n && A[i][j] == A[i + 1][j]) {
        i++;
        cnt++;
      }
      sol = __gcd(sol, cnt);
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}