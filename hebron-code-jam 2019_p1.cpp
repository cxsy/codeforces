#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e5 + 5;
ll p[N];
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  sort(p, p + n);
  ll l = 1, r = p[n - 1];
  while (l <= r) {
    ll mid = ((r - l) >> 1) + l;
    int count = 0;
    ll pre = -p[n - 1];
    for (int i = 0; i < n; i++) {
      if (p[i] - pre >= mid) {
        count++;
        pre = p[i];
      }
      if (count >= k)
        l = mid + 1;
      else
        r = mid - 1;
    }
    ll d = l - 1, pre = -d;
    for (int i = 0; i < n && k > 0; i++) {
      if (p[i] - pre >= d) {
        cout << (pre = p[i]) << " ";
        k--;
      }
    }
    return 0;
  }