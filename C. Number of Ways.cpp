#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int arr[N], dp[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int64_t sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % 3 != 0) {
    cout << 0 << "\n";
    return 0;
  }
  sum /= 3;
  int64_t t = 0;
  for (int i = 1; i <= n; i++) {
    t += arr[i];
    dp[i] = dp[i - 1] + (int)(t == sum);
  }
  int64_t ans = 0;
  t = 0;
  for (int i = n; i >= 2; i--) {
    t += arr[i];
    if (t == sum) {
      ans += dp[i - 2];
    }
  }
  cout << ans << "\n";
  return 0;
}