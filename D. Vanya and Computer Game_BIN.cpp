#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int n, x, y;
bool test(int a, int b, int mid, int v) {
  return mid + ll(1.0 * mid * b / a) >= v;
}
int bin(int a, int b, int v) {
  int l = 0, h = v;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (test(a, b, mid, v)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return h + 1;
}
void solve() {
  cin >> n >> x >> y;
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    v %= (x + y);
    int t1 = bin(x, y, v);
    int t2 = bin(y, x, v);
    if (1ll * t1 * y < 1ll * t2 * x) {
      cout << "Vanya\n";
    } else if (1ll * t1 * y > 1ll * t2 * x) {
      cout << "Vova\n";
    } else {
      cout << "Both\n";
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}