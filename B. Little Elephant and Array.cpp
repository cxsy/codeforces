#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
struct {
  int L, R, cnt;
} Q[M];
int A[N], freq[N], pre[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (A[i] < N) {
      freq[A[i]]++;
    }
  }
  for (int q = 1; q <= m; q++) {
    cin >> Q[q].L >> Q[q].R;
  }
  for (int i = 1; i <= n; i++) {
    if (A[i] < N && freq[A[i]] >= A[i]) {
      fill(pre, pre + n + 1, 0);
      for (int j = 1; j <= n; j++) {
        pre[j] = pre[j - 1] + (A[j] == A[i]);
      }
      for (int q = 1; q <= m; q++) {
        Q[q].cnt += (pre[Q[q].R] - pre[Q[q].L - 1] == A[i]);
      }
      freq[A[i]] = 0;
    }
  }
  for (int q = 1; q <= m; q++) {
    cout << Q[q].cnt << "\n";
  }
  return 0;
}