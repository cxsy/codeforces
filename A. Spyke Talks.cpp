#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int A[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, v, sol = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  for (int i = 0; i < n; i++) {
    if (A[i] == 0) continue;
    int count = 1;
    while (i + 1 < n && A[i] == A[i + 1]) {
      count++;
      i++;
    }
    if (count == 2) {
      sol++;
    } else if (count > 2) {
      cout << "-1\n";
      exit(0);
    }
  }
  cout << sol << "\n";
  return 0;
}