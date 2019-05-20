#include <bits/stdc++.h>
using namespace std;
int a00, a01, a10, a11;
void build() { cin >> a00 >> a01 >> a10 >> a11; }
void solve() {
  vector<int> v0, v1;
  if (a00 == 0) {
    v0.emplace_back(0);
    v0.emplace_back(1);
  } else {
    int c0 = int(sqrt(2 * a00)) + 1;
    if (c0 * (c0 - 1) != 2 * a00) {
      cout << "Impossible\n";
      exit(0);
    }
    v0.emplace_back(c0);
  }
  if (a11 == 0) {
    v1.emplace_back(0);
    v1.emplace_back(1);
  } else {
    int c1 = int(sqrt(2 * a11)) + 1;
    if (c1 * (c1 - 1) != 2 * a11) {
      cout << "Impossible\n";
      exit(0);
    }
    v1.emplace_back(c1);
  }
  for (int c0 : v0) {
    for (int c1 : v1) {
      if ((c0 == 0 && c1 == 0) || c0 * c1 != a01 + a10) {
        continue;
      }
      string sol = string(c0, '0') + string(c1, '1');
      int t01 = a01 + a10;
      int p0 = c0 - 1;
      while (t01 - a01 > c1) {
        swap(sol[p0], sol[p0 + c1]);
        t01 -= c1;
        p0--;
      }
      if (t01 > a01) {
        swap(sol[p0], sol[p0 + t01 - a01]);
      }
      cout << sol << "\n";
      exit(0);
    }
  }
  cout << "Impossible\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}