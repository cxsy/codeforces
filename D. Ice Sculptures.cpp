#include <bits/stdc++.h>
using namespace std;
const int NMAX = 20005;
int arr[NMAX];
int sums[NMAX];

unordered_set<int> ss;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans += arr[i];
  }
  for (int i = 2; i <= (int)sqrt(n); i++) {
    if (n % i == 0) {
      ss.insert(i);
      ss.insert(n / i);
    }
  }
  for (int f : ss) {
    if (f < 3) continue;
    fill(sums, sums + (n / f), 0);
    for (int j = 0; j < f; j++) {
      for (int i = 0; i < n / f; i++) {
        sums[i] += arr[j * (n / f) + i];
      }
    }
    for (int i = 0; i < n / f; i++) {
      ans = max(ans, sums[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}