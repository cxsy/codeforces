#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int a, t, i;
} A[N], C[N];
int n, T;
bool comp1(const node &x, const node &y) { return x.a > y.a; }
bool comp2(const node &x, const node &y) { return x.t != y.t ? x.t > y.t : x.i > y.i; }
set<node, decltype(&comp2)> ss(&comp2);
void solve() {
  cin >> n >> T;
  int a, t;
  for (int i = 0; i < n; i++) {
    cin >> a >> t;
    A[i] = {a, t, i + 1};
  }
  sort(A, A + n, comp1);
  int j = 0, tot = 0;
  for (int k = n; k >= 1; k--) {
    while (j < n && A[j].a >= k) {
      ss.insert(A[j]);
      tot += A[j].t;
      j++;
    }
    while (tot > T) {
      tot -= ss.begin()->t;
      ss.erase(ss.begin());
    }
    if (ss.size() >= k) {
      cout << k << "\n" << k << "\n";
      for (auto it = ss.begin(); it != ss.end() && k; it++) {
        cout << it->i << " \n"[next(it) == ss.end()];
        k--;
      }
      exit(0);
    }
  }
  cout << "0\n0\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}