#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int n, x, y;
void solve() {
  cin >> n >> x >> y;
  vector<string> re;
  int cntx = 0, cnty = 0;
  while (cntx <= x || cnty <= y) {
    if (1ll * (cntx + 1) * y > 1ll * (cnty + 1) * x) {
      cnty++;
      re.emplace_back("Vova");
    } else if (1ll * (cntx + 1) * y < 1ll * (cnty + 1) * x) {
      cntx++;
      re.emplace_back("Vanya");
    } else {
      cntx++;
      cnty++;
      re.emplace_back("Both");
      re.emplace_back("Both");
    }
  }
  int v;
  for (int i = 0; i < n; i++) {
    cin >> v;
    v--;
    cout << re[v % (x + y)] << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}