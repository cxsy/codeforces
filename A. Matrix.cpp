#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 4005;
int cnt[N * 9], sum[N], a;
char A[N];
void solve() {
  cin >> a >> A;
  int len = 0;
  for (int i = 0; A[i]; i++) {
    sum[i] = i == 0 ? A[i] - '0' : sum[i - 1] + A[i] - '0';
    len++;
  }
  for (int i = 0; A[i]; i++) {
    for (int j = i; A[j]; j++) {
      cnt[sum[j] - (i == 0 ? 0 : sum[i - 1])]++;
    }
  }
  ll sol = 0;
  for (int i = 0; A[i]; i++) {
    for (int j = i; A[j]; j++) {
      int t = sum[j] - (i == 0 ? 0 : sum[i - 1]);
      if (t == 0 && a == 0) {
        sol += len * (len + 1) / 2;
      } else if (t && a % t == 0) {
        sol += a / t < N * 9 ? cnt[a / t] : 0;
      }
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