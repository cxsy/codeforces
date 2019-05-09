#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int l = 0, r = n - 1;
  int ans = 0;
  while (l <= r) {
    int c = arr[r--];
    while (l <= r && c + arr[l] <= 4) {
      c += arr[l++];
    }
    ans++;
  }
  cout << ans << "\n";
  return 0;
}