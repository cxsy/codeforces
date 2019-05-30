#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9 + 5;
int A[N], P[N], n;
unordered_map<int, int> mm;
set<int> ss{0, INF};
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mm[A[0]] = 1;
  ss.insert(A[0]);
  for (int i = 1; i < n; i++) {
    auto it1 = ss.upper_bound(A[i]), it2 = prev(it1);
    P[i] = mm[*it1] > mm[*it2] ? *it1 : *it2;
    mm[A[i]] = i + 1;
    ss.insert(A[i]);
    cout << P[i] << " \n"[i == n - 1];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}