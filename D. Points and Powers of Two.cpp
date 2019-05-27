#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
vector<ii> A;
vector<ii> sol;
int n;
void output() {
  sort(sol.begin(), sol.end());
  if (sol.size() == 0) {
    cout << "1\n" << A[0].first << "\n";
    exit(0);
  }
  cout << sol.size() << "\n";
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i].second << " \n"[i == sol.size() - 1];
  }
  exit(0);
}
void solve() {
  cin >> n;
  int v;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    A.emplace_back(ii{v, i});
  }
  sort(A.begin(), A.end());
  for (ii e : A) {
    int m = e.first;
    for (int i = 0; i <= 30; i++) {
      auto it1 = lower_bound(A.begin(), A.end(), ii{m - (1 << i), 0});
      auto it2 = lower_bound(A.begin(), A.end(), ii{m + (1 << i), 0});
      if (it1->first == m - (1 << i) && it2->first == m + (1 << i)) {
        sol.clear();
        sol.emplace_back(ii{it1->second, m - (1 << i)});
        sol.emplace_back(ii{e.second, m});
        sol.emplace_back(ii{it2->second, m + (1 << i)});
        output();
      }
      if (sol.empty() && it1->first == m - (1 << i)) {
        sol.emplace_back(ii{it1->second, m - (1 << i)});
        sol.emplace_back(ii{e.second, m});
      }
    }
  }
  output();
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}