#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
int A[N], T[N];
int n, k, x;
void solve() {
  cin >> n >> k >> x;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    A[v]++;
  }
  for (int t = 0; t < k; t++) {
    fill(T, T + N, 0);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (A[i]) {
        if (cnt % 2 == 0) {
          T[i] += A[i] / 2;
          T[i ^ x] += (A[i] + 1) / 2;
        } else {
          T[i] += (A[i] + 1) / 2;
          T[i ^ x] += A[i] / 2;
        }
        cnt += A[i];
      }
    }
    copy(T, T + N, A);
  }
  for (int i = N - 1; i >= 0; i--) {
    if (A[i]) {
      cout << i << " ";
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i]) {
      cout << i << "\n";
      break;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}