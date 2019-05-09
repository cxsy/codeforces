#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 5;
const int MOD = 1e9 + 7;
int A[NMAX];
void build() {
  for (int i = 1; i < NMAX; i++) {
    A[i] = int((1LL * (A[i - 1] + 1) * (i + 1) - 1) % MOD);
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  int T, N;
  cin >> T;
  for (int i = 0; i < T; i++) cin >> N, cout << A[N] << "\n";
  return 0;
}