#include <bits/stdc++.h>
using namespace std;

const int NMAX = 105;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, t;
  double mn[NMAX];
  double p, l;
  while (cin >> m >> p >> l >> t) {
    if (m < 0) break;
    fill(begin(mn), end(mn), -1.0);
    int j = 0, mm;
    double r;
    for (int i = 0; i < t; i++) {
      cin >> mm >> r;
      mn[mm] = r;
    }
    double em = l / m;
    double val = (l + p) * (1 - mn[0]);
    if (val > l) {
      cout << 0 << " months"
           << "\n";
      continue;
    }
    int re = 1;
    r = mn[0];
    while (true) {
      if (mn[re] > 0.0) r = mn[re];
      val *= (1 - r);
      l -= em;
      if (val > l) break;
      re++;
    }
    cout << re << " month" << (re == 1 ? "" : "s") << "\n";
  }
  return 0;
}