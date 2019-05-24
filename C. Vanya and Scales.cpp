#include <bits/stdc++.h>
using namespace std;
#define exit(s) cout << (s) << "\n", exit(0);
int w, m;
void solve() {
  cin >> w >> m;
  vector<int> wb;
  bool f = true;
  while (m > 0) {
    wb.emplace_back(m % w);
    if (m % w != 0 && m % w != 1) f = false;
    m /= w;
  }
  wb.emplace_back(0);
  if (f) exit("YES");
  for (int i = 0; i < wb.size(); i++) {
    if (wb[i] == 0 || wb[i] == 1) continue;
    if (wb[i] < w - 1) exit("NO");
    wb[i + 1]++;
  }
  exit("YES");
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}