#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int A[N];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] == -1) continue;
    ans ^= 1;
    int x = i;
    while (x != -1) {
      int y = A[x];
      A[x] = -1;
      x = y;
    }
  }
  if (ans) {
    cout << "Um_nik\n";
  } else {
    cout << "Petr\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}