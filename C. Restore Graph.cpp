#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
const int N = 1e5 + 5;
ii A[N];
int n, k;
vector<int> p;
vector<ii> sol;
void solve() {
  cin >> n >> k;
  int d;
  for (int i = 0; i < n; i++) {
    cin >> d;
    A[i] = ii{d, i + 1};
  }
  sort(A, A + n);
  int st = 0, b = 1;
  int64_t cap = 1;
  for (int i = 0; i < n;) {
    int cnt = 0;
    vector<int> temp;
    while (i < n && A[i].first == st) {
      if (cnt >= cap) {
        cout << "-1\n";
        exit(0);
      }
      if (st) sol.emplace_back(ii{p[cnt / b], A[i].second});
      temp.emplace_back(A[i].second);
      cnt++;
      i++;
    }
    p = temp;
    b = k - int(st > 0);
    cap = 1ll * p.size() * b;
    st++;
  }
  cout << sol.size() << "\n";
  for (ii e : sol) {
    cout << e.first << " " << e.second << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}