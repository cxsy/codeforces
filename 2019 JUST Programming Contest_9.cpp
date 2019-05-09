#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int T, n, k;
int A[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n >> k;
    for (int j = 0; j < n; j++) cin >> A[j];
    sort(A, A + n);
    for (int j = 0; j < n; j++) {
      if (A[j] < 0) {
        if (k > 0) {
          A[j] = -A[j];
          k--;
        } else {
          break;
        }
      } else if (A[j] >= 0) {
        A[j] = k % 2 ? -A[j] : A[j];
        break;
      }
    }
    int sum = 0;
    for (int j = 0; j < n; j++) sum += A[j];
    cout << sum << "\n";
  }
  return 0;
}