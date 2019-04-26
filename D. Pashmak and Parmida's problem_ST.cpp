#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 5;
int t[2 * NMAX];
int arr[NMAX];
int n;

void inc(int p) {  // set value at position p
  for (t[p += n]++; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res += t[--r];
  }
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  unordered_map<int, int> mm;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mm[arr[i]]++;
  }
  int64_t ans = 0;
  unordered_map<int, int> mm1;
  for (int i = n - 1; i >= 0; i--) {
    ans += query(0, --mm[arr[i]]);
    inc(++mm1[arr[i]] - 1);
  }
  cout << ans << "\n";
  return 0;
}