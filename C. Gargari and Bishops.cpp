#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 2005;
int A[N][N];
ll D[N][N];
int n;
void build() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
}
void solve() {
  for (int t = 0; t <= n - 1; t++) {
    ll sum = 0;
    for (int k = 0; k <= t; k++) sum += A[k][t - k];
    for (int k = 0; k <= t; k++) D[k][t - k] += sum;
  }
  for (int t = n; t <= 2 * n - 2; t++) {
    ll sum = 0;
    for (int k = n - 1; t - k <= n - 1; k--) sum += A[k][t - k];
    for (int k = n - 1; t - k <= n - 1; k--) D[k][t - k] += sum;
  }
  for (int t = n - 1; t >= 0; t--) {
    ll sum = 0;
    for (int k = n - 1; k - t >= 0; k--) sum += A[k][k - t];
    for (int k = n - 1; k - t >= 0; k--) D[k][k - t] += sum;
  }
  for (int t = -1; t >= -n + 1; t--) {
    ll sum = 0;
    for (int k = 0; k - t <= n - 1; k++) sum += A[k][k - t];
    for (int k = 0; k - t <= n - 1; k++) D[k][k - t] += sum;
  }
  ll even = 0, odd = 0;
  int pe[2], po[2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      D[i][j] -= A[i][j];
      if ((i + j) % 2) {
        if (D[i][j] >= odd) {
          po[0] = i, po[1] = j;
          odd = D[i][j];
        }
      } else {
        if (D[i][j] >= even) {
          pe[0] = i, pe[1] = j;
          even = D[i][j];
        }
      }
    }
  }
  printf("%I64d\n", odd + even);
  printf("%d %d %d %d\n", po[0] + 1, po[1] + 1, pe[0] + 1, pe[1] + 1);
}
int main(int argc, char const *argv[]) {
  build();
  solve();
  return 0;
}