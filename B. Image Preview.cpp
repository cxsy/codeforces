#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
char S[N];
int A[N], F[N], B[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, T;
  cin >> n >> a >> b >> T;
  cin >> S;
  for (int i = 0; i < n; i++) A[i] = S[i] == 'w' ? b + 1 : 1;
  F[0] = B[0] = A[0];
  for (int i = 1; i < n; i++) F[i] = F[i - 1] + a + A[i];
  for (int i = 1; i < n; i++) B[i] = B[i - 1] + a + A[n - i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int le = T - (F[i] + i * a);
    if (le < 0) break;
    ans = max(ans, i + int(upper_bound(B, B + n, le + A[0]) - B));
  }
  for (int i = 0; i < n; i++) {
    int le = T - (B[i] + i * a);
    if (le < 0) break;
    ans = max(ans, i + int(upper_bound(F, F + n, le + A[0]) - F));
  }
  cout << min(n, ans) << "\n";
  return 0;
}