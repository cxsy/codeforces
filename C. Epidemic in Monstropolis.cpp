
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int A[N], B[N], E[N];
char C[N];
int n, k, en;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> B[i];
  }
  int i = 1, j = 1;
  while (j <= k) {
    int cnt = 0;
    int maxx = 0, st = i;
    while (i <= n && cnt < B[j]) {
      cnt += A[i];
      maxx = max(maxx, A[i]);
      i++;
    }
    if (cnt != B[j]) {
      break;
    }
    if (i == st + 1) {
      j++;
      continue;
    }
    int e = -1;
    char c;
    for (int k = st; k < i; k++) {
      if (A[k] != maxx) continue;
      if (k > st && A[k] > A[k - 1]) {
        e = k;
        c = 'L';
        break;
      }
      if (k < i - 1 && A[k] > A[k + 1]) {
        e = k;
        c = 'R';
        break;
      }
    }
    if (e == -1) {
      cout << "NO\n";
      exit(0);
    }
    if (c == 'L') {
      //   cout << st << " " << e << "\n";
      for (int k = st; k < e; k++) {
        E[en] = e - k + j;
        C[en] = 'L';
        en++;
      }
      for (int k = 0; k < i - e - 1; k++) {
        E[en] = j;
        C[en] = 'R';
        en++;
      }
    } else {
      for (int k = 0; k < i - e - 1; k++) {
        E[en] = e - st + j;
        C[en] = 'R';
        en++;
      }
      for (int k = st; k < e; k++) {
        E[en] = e - k + j;
        C[en] = 'L';
        en++;
      }
    }
    j++;
  }
  if (i != n + 1 || j != k + 1) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  for (int i = 0; i < en; i++) {
    cout << E[i] << " " << C[i] << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}