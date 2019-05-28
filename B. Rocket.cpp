#include <bits/stdc++.h>
using namespace std;
int m, n;
int ask(int x) {
  cout << x << "\n";
  fflush(stdout);
  cin >> x;
  return x;
}
void solve() {
  cin >> m >> n;
  int a;
  vector<int> e(n);
  for (int i = 0; i < n; i++) {
    a = ask(m);
    if (a == 0) {
      exit(0);
    }
    e[i] = -a;
  }
  int l = 1, h = m, i = 0;
  while (l <= h) {
    int mid = (l + h) >> 1;
    a = ask(mid);
    if (a * e[i % n] == 0) {
      exit(0);
    } else if (a * e[i % n] == 1) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
    i++;
  }
}
int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  solve();
  return 0;
}