#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int K = 2005;
int people[N], keys[K];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, p;
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) cin >> people[i];
  for (int i = 0; i < k; i++) cin >> keys[i];
  sort(people, people + n);
  sort(keys, keys + k);
  int ans = 2e9 + 5;
  for (int i = 0; i <= k - n; i++) {
    int local = -1;
    for (int j = i; j < i + n; j++) {
      local = max(local, abs(keys[j] - people[j - i]) + abs(p - keys[j]));
    }
    ans = min(ans, local);
  }
  cout << ans << "\n";
  return 0;
}