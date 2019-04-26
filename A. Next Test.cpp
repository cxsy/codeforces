#include <bits/stdc++.h>
using namespace std;

const int NMAX = 3005;
int arr[NMAX];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] != ans) {
      cout << ans << "\n";
      return 0;
    }
    ans++;
  }
  cout << ans << "\n";
  return 0;
}